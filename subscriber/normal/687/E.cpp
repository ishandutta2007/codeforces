#include<bits/stdc++.h>
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

vector<int> v[5555], rev[5555];
vector<int> order;

int was[5555];
int bd[5555];

int n, m;

void go(int x) {
	was[x] = 1;
	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i];
		if (!was[to]) go(to);
	}
	order.pb(x);
}

vector<int> cur;

vector<vector<int> > comps;

void rec(int x) {
	was[x] = 1;
	cur.pb(x);
	for (int i = 0; i < rev[x].size(); i++) {
		int to = rev[x][i];
		if (was[to] == -1) rec(to);
	}
}

int my[5555];
int T;

int q[5555], q1, q2;
int d[5555];

int solve(vector<int> t) {
	if (t.size() == 1) return 1;
//	for (int i = 0; i < t.size(); i++) cout << t[i] << " ";
//	cout << endl;
	T++;
	for (int i = 0; i < t.size(); i++) my[t[i]] = T;
	random_shuffle(t.begin(), t.end());
	
	int ret = 1e9 + 1;
	for (int i = 0; i < t.size(); i++) {
		q1 = q2 = 0;
		for (int j = 0; j < t.size(); j++) d[t[j]] = -1;
		d[t[i]] = 0;
		q[q1++] = t[i];

		while (q1 != q2) {
			int x = q[q2++];
			if (d[x] + 1 < ret) for (int j = 0; j < v[x].size(); j++) {
				int to = v[x][j];
				if (to == t[i]) ret = min(ret, d[x] + 1);
				if (my[to] != T || d[to] != -1) continue;
				d[to] = d[x] + 1;
				q[q1++] = to;
			}
		}
	}
	return ret * 998 + 1 + t.size();
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].pb(y);
		rev[y].pb(x);
	}
	for (int i = 0; i < n; i++) if (!was[i]) go(i);

	for (int i = 0; i < n; i++) was[i] = -1;
	
	for (int i = order.size() - 1; i >= 0; i--) if (was[order[i]] == -1) {
		cur.clear();
		rec(order[i]);
		comps.pb(cur);
	}
	reverse(comps.begin(), comps.end());

	int ans = 0;
	for (int i = 0; i < comps.size(); i++) {
		int bad = 0;
		vector<int> cur = comps[i];
		for (int j = 0; j < cur.size(); j++) if (bd[cur[j]]) bad = 1;
		if (!bad) ans += solve(cur); else ans += cur.size();

		for (int j = 0; j < cur.size(); j++) for (int k = 0; k < rev[cur[j]].size(); k++) bd[rev[cur[j]][k]] = 1;
	}
	cout << ans << endl;

	return 0;
}