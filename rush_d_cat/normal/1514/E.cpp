#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100 + 10;

int f[N][N];

bool leq(int x, int y) {
	printf("%d %d %d\n", 1,x-1,y-1); fflush(stdout);
	int r; scanf("%d",&r);
	return r;
}

vector<int> sort(vector<int> v) {
	// for (auto x: v) cout << x << " "; cout << endl;
	if (v.size() <= 1) return v;
	vector<int> vl, vr;
	int mid = v.size() / 2;
	for (int i = 0; i < mid; i ++) vl.push_back(v[i]);
	for (int i = mid; i < v.size(); i ++) vr.push_back(v[i]);
	vl = sort(vl), vr = sort(vr);
	int i = 0, j = 0;
	vector<int> res;
	while (i < vl.size() || j < vr.size()) {
		if (i == (int)vl.size()) {
			res.push_back(vr[j++]);
		} else if (j == (int)vr.size()) {
			res.push_back(vl[i++]);
		} else {
			if (leq(vl[i], vr[j])) {
				res.push_back(vl[i++]);
			} else {
				res.push_back(vr[j++]);
			}
		}
	}
	return res;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t --) {
		int n;
		scanf("%d", &n);
		vector<int> v(n);
		iota(v.begin(), v.end(), 1);
 
		v = sort(v);
		vector<int> idx(n + 1, 0);
 
		auto ask = [&](int r,int p) {
			printf("%d %d %d", 2,v[p]-1,r+1); fflush(stdout);
			for (int i = 0; i <= r; i ++) printf(" %d", v[i]-1);
			printf("\n"); fflush(stdout);
			int res; scanf("%d",&res);
			return res;	
		};

		//for (auto x: v) cout << x-1 << " "; cout << endl;
		int C = 0, pre = v.size() - 1;
		for (int i = v.size() - 1, j = v.size() - 1; i >= -1; i --) {
			if (i == j) {
				++ C;
				for (int x = pre; x > i; x --) {
					idx[v[x]] = C;
				}
				pre = i, -- j;
			}
			while (j >= 0 && ask(j, i)) j --;
		}

		printf("3\n");fflush(stdout);
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				if (idx[i] >= idx[j]) printf("1"); else printf("0");
			}
			printf("\n"); fflush(stdout);
		}
		int x; scanf("%d", &x);
	}

}