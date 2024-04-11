#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll MOD = 1000000007;
const ll INFLL = 1e12;
const int INF = 1e9;
const int MAX_N = 80;

int N, K;
ll cost[MAX_N+1][MAX_N+1];
ll dist[MAX_N+1], dist2[MAX_N+1];
vector<pll> c[MAX_N+1][MAX_N+1];
ll ans = INFLL;
vector<int> v;
int cnt[MAX_N+1];

void solve(int x){
	if(x==K){
		v.pb(1);
		ll sum = 0;
		for(int i=0; i<v.size()-1; i++){
			int idx = 0;
			while(idx<c[v[i]][v[i+1]].size() && cnt[c[v[i]][v[i+1]][idx].second]!=0)	idx++;
			if(idx==c[v[i]][v[i+1]].size()){
				sum = -1;
				break;
			}
			sum+=c[v[i]][v[i+1]][idx].first;
		}
		if(sum!=-1){
			ans = min(ans, sum);
		}
		v.pop_back();
		return;
	}else{
		for(int i=1; i<=N; i++){
			v.pb(i);
			cnt[i]++;
			solve(x+1);
			cnt[i]--;
			v.pop_back();
		}
	}
}


int main(){
	scanf("%d%d", &N, &K);
	K = K/2 -1;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%lld", &cost[i][j]);
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			for(int k=1; k<=N; k++){
				if(k==i || k==j)	continue;
				c[i][j].pb({cost[i][k] + cost[k][j], k});
			}
			sort(c[i][j].begin(), c[i][j].end());
		}
	}
	cnt[1]++;
	v.pb(1);
	solve(0);
	printf("%lld", ans);
	return 0;
}