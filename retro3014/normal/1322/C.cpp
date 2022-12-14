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
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 500000;

int N, M;
int T;
ll c[MAX_N+1];
vector<int> gp[MAX_N+1];
int group[MAX_N+1];
int to[MAX_N*2+1];
vector<int> v;
ll sum[MAX_N*2+1];

ll gcd(ll x, ll y){
	return (y==0)?x:gcd(y, x%y);
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &M);
		for(int i=1; i<=N; i++){
			scanf("%lld", &c[i]);
			while(!gp[i].empty())	gp[i].pop_back();
			group[i] = 1;
		}
		for(int i=1; i<=M; i++){
			int a, b; scanf("%d%d", &a, &b);
			gp[a].pb(b);
		}
		int gsize = 1;
		for(int i=1; i<=N; i++){
			for(int j : gp[i]){
				if(to[group[j]]==0){
					to[group[j]] = gsize+1;
					gsize++;
					v.pb(group[j]);
				}
				group[j] = to[group[j]];
			}
			while(!v.empty()){
				to[v.back()] = 0;
				v.pop_back();
			}
		}
		for(int i=1; i<=N; i++){
			sum[group[i]]+=c[i];
		}
		ll ans = 0;
		for(int i=2; i<=gsize; i++){
			ans = gcd(ans, sum[i]);
			sum[i] = 0;
		}
		printf("%lld\n", ans);
	}
	return 0;
}