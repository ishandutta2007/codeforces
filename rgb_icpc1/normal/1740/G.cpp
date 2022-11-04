#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
#define endl '\n'
using LL = long long;
using PII = pair<int, int>;
using VI = vector<int>;
using VPII = vector <PII>;
const int MN = 1005;
int a[MN][MN];
bool b[MN][MN];
bool c[4][MN][MN];
bool d[4][MN][MN];
int e[4][MN][MN];
int f[4][MN][MN];
int id[4][MN][MN];
vector<int> V;

int n, m;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	V.clear();
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) V.push_back(i * m + j);
	sort(V.begin(), V.end(), [](int i, int j) { return a[i / m][i % m] < a[j / m][j % m]; });
	
	for (int k = 0; k < 4; k++) for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		c[k][i][j] = d[k][i][j] = 1;
		id[k][i][j] = k * n * m + i * m + j;
		e[k][i][j] = f[k][i][j] = id[k][i][j];
	}
	
	for (auto v : V) {
		int i = v / m, j = v % m;
		b[i][j] = 0;
//		cout << "step : " << a[i][j] << endl;
		for (int dd = 0; dd < 4; dd++) {
//			cout << dd << ' ' << d[dd][i][j] << ' ' << c[dd][i][j] << endl;
			b[i][j] ^= ((a[i][j] & 1) & d[dd][i][j]) ^ c[dd][i][j];
		}
//		cout << b[i][j] << endl;
		for (int dd = 0; dd < 4; dd++) {
			int ddd = (dd + 2 + b[i][j]) % 4;
			int ii = i + di[ddd], jj = j + dj[ddd];
			if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
			int id1 = e[ddd ^ 2][ii][jj];
			int d1 = id1 / (n * m), i1 = (id1 % (n * m)) / m, j1 = (id1 % (n * m)) % m;
//			cout << d1 << ' ' << i1 << ' ' << j1 << ' ' << d[d1][i1][j1] << ' ' << c[d1][i1][j1] << ' ' << d[dd][i][j] << ' ' << (a[i][j] & 1) << endl;
			d[d1][i1][j1] ^= d[dd][i][j];
			c[d1][i1][j1] ^= (d[dd][i][j] & (a[i][j] & 1));
			f[d1][i1][j1] = f[dd][i][j];
			int id2 = f[dd][i][j];
			int d2 = id2 / (n * m), i2 = (id2 % (n * m)) / m, j2 = (id2 % (n * m)) % m;
			e[d2][i2][j2] = id1;
//			cout << d1 << ' ' << i1 << ' ' << j1 << ' ' << d[d1][i1][j1] << ' ' << c[d1][i1][j1] << ' ' << d2 << ' ' << i2 << ' ' << j2 << endl;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << b[i][j];
		cout << endl;
	}
		
	return 0;
	
}