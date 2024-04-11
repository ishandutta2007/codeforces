#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <stack>
#include <cassert>
#include <list>
//#include <unordered_set>
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
void solve();

int main() {
#ifdef DEBUG
	freopen("input", "r", stdin);
	//freopen("output", "w", stdout);
	clock_t start = clock();
#else
#endif
	ios_base::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

#ifdef DEBUG
	//cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}


int a[101010], b[101010];
const int shift = 1 << 17;
int tree[shift * 2];

inline int rget(int v) {
	if(!v)
		return -2;
	return max(rget(v / 2), tree[v]); 
}

int get(int v){
	return rget(v + shift);
}

void rset(int l, int r, int v) {
	if(l > r)
		return;
	if(l % 2 == 1){
		tree[l] = v;
		return rset(l + 1, r , v);
	}
	if(r % 2 == 0){
		tree[r] = v;
		return rset(l, r - 1, v);
	}
	return rset(l / 2, r / 2, v);

}

void  set(int l, int r, int v){
	return rset(l + shift, r + shift, v);

}

int delta[101010];

void solve() {
	int n, m;
	cin >> n >> m;

	memset(tree, -1, sizeof tree);

	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];

	for(int i = 0; i < m; ++i){
		int o;
		cin >> o;

		if( o == 1){
			int x, y, k;
			cin >> x >> y >> k;
			--x, --y;
			delta[i] = y - x;
			set(y, y + k - 1, i);
		}
		else {
			int p;
			cin >> p;
			--p;

			int mx = get(p);
			if(mx == -1)
				cout << b[p];
			else {
				cout << a[p - delta[mx]];
			}
			cout << '\n';
		}
	}

}