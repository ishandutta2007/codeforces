#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n;
int p[310];
int st[310];
string s[310];
vector<int> vec[310];

void dfs(int v, int k) 
{
	st[v] = k;
	vec[k].pb(v);

	rep(i, n) if (s[v][i] == '1') {
		if (st[i] == -1) {
			dfs(i, k);
		}
	}
}

int main() {
	cin >> n;

	rep(i, n) cin >> p[i];
	rep(i, n) cin >> s[i];
	
	memset(st, -1, sizeof(st));
	int now = 0;
	rep(i, n) if (st[i] == -1) dfs(i, now++);

	rep(i, now) {
		vector<int> vals, ids;

		rep(j, vec[i].size()) {
			vals.eb(p[vec[i][j]]);
			ids.eb(vec[i][j]);
		}

		sort(ALL(vals));
		sort(ALL(ids));	

		rep(j, vals.size()) p[ids[j]] = vals[j];
	}

	rep(i, n) printf("%d%c", p[i], i == n - 1 ? '\n' : ' ');

	return 0;
}