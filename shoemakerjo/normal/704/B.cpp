#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 5010

const ll inf = 1LL << 62;
ll x[maxn];
ll a[maxn];
ll b[maxn];
ll c[maxn];
ll d[maxn];
int n, s, e;

//dp on which number we are on by the number of groups there are
ll dp[maxn][maxn];

ll go(int ind, int groups) {
	if (groups < 0) return inf;
	if (ind == 1) {
		ll ans = go(ind+1, 1); //just add it loosely (we have to)
		if (ind == s) {
			ans += d[ind];
		}
		else if (ind == e) {
			ans += b[ind];
		}
		else {
			ans += b[ind] + d[ind];
		}
		return ans;
	}
	if (groups == 0) return inf; //illegal past 0 

	if (ind == n+1) {
		if (groups != 1) return inf;
		return 0LL;
	}
	if (dp[ind][groups] != inf) return dp[ind][groups];
	int openspots = 0;
	openspots += 2*groups; //everything

	bool leftclosed = ind > s;
	bool rightclosed = ind > e;

	if (leftclosed) openspots--;
	if (rightclosed) openspots--;

	if (openspots <= 0) return inf; //this means we are at one group and bounded (oops)

	ll cbuff = openspots * (x[ind] - x[ind-1]);

	if (ind == s) {
		ll ans = inf;
		//option 1 is to bind to the leftmost
		ll o1 = c[ind] + go(ind+1, groups);
		//option 2 is to add loosely
		ll o2 = d[ind] + go(ind+1, groups+1);
		ans = min(o1, o2);
		return dp[ind][groups] = ans + cbuff;
	}
	if (ind == e) {
		ll ans = inf;
		//option 1 is to bind to the rightmost
		ll o1 = a[ind] + go(ind+1, groups);
		//option 2 is to place loosely
		ll o2 = b[ind] + go(ind+1, groups+1);
		ans = min(o1, o2);
		return dp[ind][groups] = ans + cbuff;
	}
	ll ans = inf;
	//option 1 is just to place loosely
	ll o1 = b[ind] + d[ind] + go(ind+1, groups+1);
	//option 2 is to bind me to two guys
	ll o2 = inf;
	if (groups >= 2) {
		o2 = a[ind] + c[ind] + go(ind+1, groups-1);
	}
	//option 3 is to bind to the left of a group
	ll o3 = inf;
	if (!(groups == 1 && leftclosed)) {
		o3 = b[ind] + c[ind] + go(ind+1, groups);
	}
	//option 4 is to bind to the right of a group
	ll o4 = inf;
	if (!(groups == 1 && rightclosed)) {
		o4 = a[ind] + d[ind] + go(ind+1, groups);
	}
	ans = min(ans, o1); ans = min(ans, o2); ans = min(ans, o3); ans = min(ans, o4);
	ans += cbuff;
	return dp[ind][groups] = ans;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < maxn; i++) fill(dp[i], dp[i]+maxn, inf); //-1 means unprocessed
	cin >> n >> s >> e;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) cin >> d[i];
	cout << go(1, 0) << endl;
}