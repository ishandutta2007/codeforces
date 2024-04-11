#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, k;
int a[N];
vector<int> v[N];

int cost[N], del[N], was[N], h[N];

int q[N], q1, q2;

int mid;

int T;
vector<int> cur;

void col(int x) {
	if (a[x] < mid || was[x]) return;
	was[x] = T;
	cur.pb(x);
	h[x] = v[x].size();
	cost[x] = 1;
	for (int i = 0; i < v[x].size(); i++) col(v[x][i]);
}

int best;

int go(int x, int pr) {
	vector<int> ch;
	for (int i = 0; i < v[x].size(); i++) {
		int u = v[x][i];
		if (was[u] != T || del[u] || u == pr) continue;
		ch.pb(go(u, x));
	}
	best = max(best, cost[x]);
	int ma = 0;
	for (int i = 0; i < ch.size(); i++) {
		best = max(best, cost[x] + ma + ch[i]);
		ma = max(ma, ch[i]);
	}
	return ma + cost[x];
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	cin >> n >> k;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	int l = 0;
	int r = 1e6 + 5;

	while (l < r) {
		mid = (l + r + 1) / 2;
//		mid = 2;

		int ok = 0;
		for (int i = 0; i < n; i++) was[i] = 0;
		for (int i = 0; i < n; i++) del[i] = 0;
		T = 0;
		for (int i = 0; i < n; i++) if (!was[i] && a[i] >= mid) {
			cur.clear();
			T++;
			col(i);
			q1 = q2 = 0;
			for (int i = 0; i < cur.size(); i++) if (h[cur[i]] == 1) {
				q[q1++] = cur[i];
			}
		
			while (q1 != q2) {
				int x = q[q2++];
				int to = -1;
				for (int i = 0; i < v[x].size(); i++) {
					int u = v[x][i];
					if (was[u] != T || del[u]) continue;
					to = u;
				}
				if (to == -1) continue;
				del[x] = 1;
				cost[to] += cost[x];
				h[to]--;
				if (h[to] == 1) q[q1++] = to;
			}

			best = 0;
			for (int i = 0; i < cur.size(); i++) if (!del[cur[i]]) {
				go(cur[i], -1);
				break;
			}
			if (best >= k) ok = 1;
		}
//		cout << mid << " " << ok << endl;
		if (ok) l = mid; else r = mid - 1;

	}
	cout << l << endl;

	return 0;
}