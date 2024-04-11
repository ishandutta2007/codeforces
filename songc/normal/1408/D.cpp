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
int N, M, ans=1234567890;
pii A[2020], B[2020];
vector<pii> V, P;

int main(){
	scanf("%d %d", &N, &M);
	for (int i=1; i<=N; i++) scanf("%d %d", &A[i].fi, &A[i].se);
	for (int i=1; i<=M; i++) scanf("%d %d", &B[i].fi, &B[i].se);
	for (int i=1; i<=N; i++) for (int j=1; j<=M; j++){
		if (A[i].fi<=B[j].fi && A[i].se<=B[j].se) V.pb(pii(B[j].fi-A[i].fi, B[j].se-A[i].se));
	}
	V.pb(pii(12345678, -1));
	V.pb(pii(-1, 12345678));
	sort(all(V));
	for (pii t : V){
		while (P.size() && P.back().se<=t.se) P.pop_back();
		P.pb(t);
	}
	for (int i=1; i<P.size(); i++) ans = min(ans, P[i].se+P[i-1].fi+2);
	printf("%d\n", ans);
	return 0;
}