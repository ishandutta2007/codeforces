#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define test 1
#define TEST if(test)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MOD = 1000000007; // 998244353
const ll INF = 2e9;
const ll INFLL = 3e18;
const int MAX_N = 1;

int T;
int N[3];
vector<ll> v[3];
vector<pll> vt;

ll calc(ll x, ll y, ll z){
	return (x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x);
}

ll ans;

int main(){
	scanf("%d", &T);
	while(T--){
		ans = INFLL;
		scanf("%d%d%d", &N[0], &N[1], &N[2]);
		while(!vt.empty())	vt.pop_back();
		for(int t=0; t<3; t++){
			while(!v[t].empty())	v[t].pop_back();
			for(int i=1; i<=N[t]; i++){
				ll x;scanf("%lld", &x);
				v[t].pb(x);
				vt.pb({x, t});
			}
			sort(v[t].begin(), v[t].end());
		}
		sort(vt.begin(), vt.end());
		int idx[3] = {0, 0, 0};
		ll n[3] = {v[0][0], v[1][0], v[2][0]};
		ll pn[3] = {-INF, -INF, -INF};
		for(int i=0; i<vt.size(); i++){
			ll now = vt[i].first;
			int t = (int)vt[i].second;
			idx[t]++;
			pn[t] = now;
			if(idx[t]==(int)v[t].size()){
				n[t] = INF;
			}else{
				n[t] = v[t][idx[t]];
			}
			if(pn[(t+1)%3]!=-INF && n[(t+2)%3]!=INF){
				ans = min(ans, calc(now, pn[(t+1)%3], n[(t+2)%3]));
			}
			if(pn[(t+2)%3]!=-INF && n[(t+1)%3]!=INF){
				ans = min(ans, calc(now, pn[(t+2)%3], n[(t+1)%3]));
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}