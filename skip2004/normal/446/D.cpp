#include<bits/stdc++.h>
using std::cin;
using std::cout;
int n, m, k;
typedef double db;
const int N = 510, M = 100100;
db a[N][N];
int lim;

const db eps = 1e-10;
using DI = db[N];
struct Mat {
	DI a[N];
	inline void clear() {
		for(int i = 0;i < N;++i)
			for(int j = 0;j < N;++j)
				a[i][j] = 0;
	}
	inline DI& operator [](int index) { return a[index]; }
	inline const DI& operator [](int index) const { return a[index]; }
	inline Mat operator * (const Mat & b) const {
		Mat ret; ret.clear();
		for(int i = 0;i < lim;++i) {
			for(int j = 0;j < lim;++j) if(a[i][j] > eps) {
				for(int k = 0;k < lim;++k) {
					ret[i][k] += a[i][j] * b[j][k];
				}
			}
		}
		for(int i = 0;i < lim;++i) {
			db sum = 0;
			for(int j = 0;j < lim;++j) sum += ret[i][j];
			if(sum > eps)
				for(int j = 0;j < lim;++j) ret[i][j] *= 1 / sum;
		}
		return ret;
	}
};

std::vector<int> vc[N];
int bad[N], x[N];

Mat trans, mt, start;

int ind[N], tot;

inline Mat pow(Mat a, int b) {
	Mat ans; ans.clear();
	for(int i = 0;i < lim;++i) ans[i][i] = 1;
	for(;b;b >>= 1, a = a * a) if(b & 1)
		ans = ans * a;
	return ans;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;++i) {
		cin >> bad[i];
	}
	for(int i = 0;i < m;++i) {
		int x, y;
		cin >> x >> y;
		vc[x].push_back(y);
		vc[y].push_back(x);
	}
	for(int i = 1;i <= n;++i) if(!bad[i]) {
		for(int to : vc[i]) {
			trans[i][to] += 1. / vc[i].size();
		}
	} else {
		trans[i][i] = 1;
	}
	lim = n + 1;
	for(int i = 0;i < 32;++i) trans = trans * trans;
	for(int i = 1;i <= n;++i) if(bad[i]) {
		trans[i][i] = 0;
		for(int to : vc[i]) {
			if(bad[to]) trans[i][to] += 1;
			else for(int j = 1;j <= n;++j) trans[i][j] += trans[to][j];
		}
		for(int j = 1;j <= n;++j) trans[i][j] /= vc[i].size();
	}
	for(int i = 1;i <= n;++i) if(bad[i]) {
		ind[i] = tot ++;
		start.a[0][tot - 1] = trans[1][i];
	}
	lim = tot;
	for(int i = 1;i <= n;++i) if(bad[i]) {
		for(int j = 1;j <= n;++j) if(bad[j]) {
			mt[ind[i]][ind[j]] = trans[i][j];
		}
	}
	start = start * pow(mt, k - 2);
	printf("%.10lf\n", start.a[0][tot - 1]);
}