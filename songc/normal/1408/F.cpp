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

int N, num;
vector<pii> ans;
vector<int> V;

int main(){
	scanf("%d", &N);
	int t;
	for (t=0; (1<<t)<=N; t++){
		for (int j=0; j<N; j++){
			if (!(j&(1<<t)) && (j|((1<<t+1)-1))<N) ans.pb(pii(j, j|(1<<t)));
		}
	} t--;
	for (int s=1; s<(1<<t); s<<=1){
		if (N&s){
			if (V.empty()){
				for (int j=0; j<s; j++){
					int x = (N&(~(2*s-1)))+j;
					ans.pb(pii(x, num));
					V.pb(x), V.pb(num);
					num++;
				}
			}
			else{
				for (int j=0; j<s; j++){
					int x = (N&(~(2*s-1)))+j;
					ans.pb(pii(x, V[j])), V.pb(x);
				}
			}
		}
		else{
			if (V.empty()) continue;
			for (int j=0; j<s; j++){
				ans.pb(pii(V[j], num));
				V.pb(num);
				num++;
			}
		}
	}
	printf("%d\n", (int)ans.size());
	for (pii t : ans) printf("%d %d\n", t.fi+1, t.se+1); 
	return 0;
}