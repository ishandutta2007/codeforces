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
#define M 1000000007
#define N 811111
using namespace std;
typedef pair<int,int> pt;

int n, d;
long long h[N];
pair<long long, int> q[N];
pt s[N];
int dp[N], pr[N];
int u[N];


void add(int pos, int l, int r, int x, pt v) {
	if (x < l || x > r) return;
	if (l == r) {
		s[pos] = max(s[pos], v);
		return;
	}
	add(pos + pos, l, (l + r) / 2, x, v);
	add(pos + pos + 1, (l + r) / 2 + 1, r, x, v);
	s[pos] = max(s[pos + pos], s[pos + pos + 1]);
}

pt fin(int pos, int l, int r, int ll, int rr) {
	ll = max(ll, l);
	rr = min(rr, r);
	if (ll > rr) return mp(0, 0);
	if (l == ll && r == rr) return s[pos];

	return max( fin(pos + pos, l, (l + r) / 2, ll, rr), fin(pos + pos + 1, (l + r) / 2 + 1, r, ll, rr));
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &h[i]);
		q[i] = mp(h[i], i);
	}
	sort(q, q + n);
	for (int i = 0; i < n; i++) u[q[i].S] = i;

	for (int i = 0; i < n; i++) {
		int ri = upper_bound(q, q + n, mp(h[i] + d - 1, (int) 1e9)) - q - 1;

		int le = upper_bound(q, q + n, mp(h[i] - d, (int) 1e9)) - q;

		pair<int, int> v = max( fin(1, 0, n - 1, 0, le - 1), fin(1, 0, n - 1, ri + 1, n - 1));
		dp[i] = v.F + 1;
		pr[i] = v.S;

		add(1, 0, n - 1, u[i], mp(dp[i], i));

	}
	int x = 0;
	for (int i = 1; i < n; i++) if (dp[i] > dp[x]) x = i;
	vector<int> ans;
	ans.pb(x + 1);
	while (dp[x] > 1) {
		x = pr[x];
		ans.pb(x + 1);
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size() - 1; i++) printf("%d ", ans[i]);
	cout << ans.back() << endl;

	return 0;
}