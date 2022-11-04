#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
#define pb push_back
#define pob pop_back
#define endl '\n'
using LL = long long;
using PI = pair<int, int>;
const int N = 1000005;

const int MAXN = 210000;

struct UnionSet {
	int f[MAXN], cnt;
	UnionSet(int n = 0) { prepare(n); }
	inline int find_set(int x) {
		return f[x] == x ? x : f[x] = find_set(f[x]);
	}
	inline int unite(int x, int y) {
		x = find_set(x);
		y = find_set(y);
		if (x == y) return 0;
		f[x] = y;
		cnt --;
		return 1;
	}
	inline void prepare(int n) {
		for (int i = 1; i <= n; i++) f[i] = i;
		cnt = n;
	}
} dsu;

int last[N];
bool good[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int Tc, n;
	string s;
	for (cin >> Tc; Tc --;) {
		cin >> n;
		dsu.prepare(2 * n);
		cin >> s;
		for (int i = 0; i <= 2 * n; i ++) last[i] = -1;
		for (int i = 0; i <= 2 * n; i ++) good[i] = 0;
		int cur = 0;
		for (int i = 0; i < 2 * n; i ++) {
			if (s[i] == '(') {
				cur ++;
				last[cur] = i + 1;
			}
			if (s[i] == ')') {
				if (last[cur] != -1) {
					dsu.unite(last[cur], i + 1);
					good[i] = 1;
					if (last[cur] > 1 && s[last[cur] - 2] == ')' && good[last[cur] - 2]) dsu.unite(i + 1, last[cur] - 1);
				}
				cur --;
			}
		}
		cout << dsu.cnt << endl;
	}
	
	return 0;
}