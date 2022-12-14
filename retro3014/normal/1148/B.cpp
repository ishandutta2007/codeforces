#include <bits/stdc++.h>

#define pb push_back
#define all(v) ((v).begin(), (v).end())
#define sortv(v) sort(all(v))
#define sz(v) ((int)(v).size())
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define umax(a, b) (a)=max((a), (b))
#define umin(a, b) (a)=min((a), (b))
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define rep(i,n) FOR(i,1,n)
#define rep0(i,n) FOR(i,0,(int)(n)-1)
#define FI first
#define SE second
#define INF 2000000000
#define INFLL 1000000000000000000LL


using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
int K;
vector<ll> A, B;
int TA, TB;

ll ans = 0;

int main(){
	cin>>N>>M>>TA>>TB>>K;
	for(int i=0; i<N; i++){
		ll x; scanf("%lld", &x);
		A.pb(x + TA);
	}for(int i=0; i<M; i++){
		ll x; scanf("%lld", &x);
		B.pb(x);
	}
	if(K>=N || K>=M){
		printf("-1");
		return 0;
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int idx2 = 0;
	for(int i=0; i<=K; i++){
		int j = K-i;
		ll t = A[i];
		while(idx2<B.size() && B[idx2]<t){
			idx2++;
		}
		if(idx2 + j>= B.size()){
			ans = max(ans, INFLL);
		}else{
			ans = max(ans, B[idx2+j]+TB);
		}
	}
	if(ans==INFLL){
		printf("-1");
	}else{
		printf("%lld", ans);
	}
	return 0;
}