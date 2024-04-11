#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define MOD1 993244853
#define MOD2 1000000007
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;

int tc, N, M;
LL ans;
LL A[505050], S[505050];
pii H[505050];
vector<int> T[505050];
vector<pii> comp;

int main(){
	scanf("%d", &tc);
	while (tc--){
		comp.clear(), ans=0;
		scanf("%d %d", &N, &M);
		for (int i=1; i<=N; i++){
			S[i]=0, T[i].clear();
			scanf("%lld", &A[i]);
		}
		for (int i=1; i<=M; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			T[v].pb(u);
		}
		for (int i=1; i<=N; i++){
			if (T[i].empty()) continue;
			sort(all(T[i]));
			H[i]=pii(0,0);
			for (int x : T[i]){
				H[i].first = (H[i].first*505051+x)%MOD1;
				H[i].second = (H[i].second*505067+x)%MOD2;
			}
			comp.pb(H[i]);
		}
		sort(all(comp));
		comp.erase(unique(all(comp)), comp.end());
		for (int i=1; i<=N; i++) if (T[i].size()) S[lb(all(comp), H[i])-comp.begin()+1] += A[i];
		for (int i=1; i<=comp.size(); i++) ans = __gcd(ans, S[i]);
		printf("%lld\n", ans);
	}
	return 0;
}