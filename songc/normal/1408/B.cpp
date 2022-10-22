#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define Mup(a,x) a=max(a, x)
#define mup(a,x) a=min(a, x)
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define INF (1ll<<60)
#define MOD 1'000'000'007 
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC;
int N, K;
vector<int> V;

int main(){
	scanf("%d", &TC);
	while (TC--){
		V.clear();
		scanf("%d %d", &N, &K);
		for (int i=1; i<=N; i++){
			int a;
			scanf("%d", &a);
			V.pb(a);
		}
		V.erase(unique(all(V)), V.end());
		if (V.size() == 1) puts("1");
		else if (K == 1) puts("-1");
		else printf("%d\n", ((int)V.size()-1+K-2)/(K-1));
	}
	return 0;
}