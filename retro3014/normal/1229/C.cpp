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
const int MAX_N = 100000;

int N, M, Q;
vector<int> gp[MAX_N+1];
vector<int> idx[MAX_N+1];
int num[MAX_N+1];
ll ans;

int main(){
	scanf("%d%d", &N, &M);
	for(int i=1; i<=M; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		gp[a].pb(b); gp[b].pb(a);
	}
	for(int i=1; i<=N; i++){
		num[i] = gp[i].size();
		for(int j : gp[i]){
			if(j>i){
				idx[i].pb(j);
			}
		}
	}
	for(int i=1; i<=N; i++){
		ans += (ll)(idx[i].size()) * (ll)(num[i] - idx[i].size());
	}
	printf("%lld\n", ans);
	scanf("%d", &Q);
	for(int i=1; i<=Q; i++){
		int x; scanf("%d", &x);
		ans -= (ll)(idx[x].size()) * (ll)(num[x] - idx[x].size());

		while(!idx[x].empty()){
			int now = idx[x].back(); idx[x].pop_back();
			ans -= (ll)(idx[now].size()) * (ll)(num[now] - idx[now].size());
			idx[now].pb(x);
			ans += (ll)(idx[now].size()) * (ll)(num[now] - idx[now].size());
		}
		printf("%lld\n", ans);
	}
	return 0;
}