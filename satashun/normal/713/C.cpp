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

const ll INF = LLONG_MAX;

int n;
vector<int> xs;
int a[3010];
vector<ll> dp[2];
map<int, int> cnts;
vi pts;

int main() {
	scanf("%d", &n);

	rep(i, n) {
		scanf("%d", &a[i]);
		a[i]-=i;

		pts.pb(a[i]);
		++cnts[a[i]];

		xs.pb(a[i]-1);
		xs.pb(a[i]);
		xs.pb(a[i]+1);
	}

	sort(ALL(pts));


	for (const pii p : cnts) {
		int num = p.se, cent = p.fi;
		for (int i = cent - num; i <= cent + num; ++i) {
			xs.pb(i);
		}
	}

	sort(ALL(xs));
	xs.erase(unique(ALL(xs)), xs.end());

	rep(i, 2) dp[i].resize((int)xs.size(), INF);
	rep(i, xs.size()) dp[0][i] = abs(a[0]-xs[i]);

	int c=0,f=1;

	for (int i = 1; i < n; ++i) {
		ll amin = LLONG_MAX;

		rep(j, xs.size()) {
			amin = min(amin, dp[c][j]);	
			if (amin == INF) dp[f][j] = INF;
			else {
				dp[f][j] = amin + abs(a[i]-xs[j]);
			}
			//amin = min(amin, dp[c][j]);
		}

		swap(c, f);
		//rep(j, xs.size()) cout << dp[c][j] << " ";
		//cout << endl;
	}

	cout<<*min_element(ALL(dp[c]))<<endl;

	return 0;
}