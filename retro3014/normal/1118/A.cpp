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

int Q;
ll N, A, B;

int main(){
	scanf("%d", &Q);
	for(int i=0; i<Q; i++){
		scanf("%lld%lld%lld", &N, &A, &B);
		if(A*2>B){
			printf("%lld\n", (N/2)*B+(N%2)*A);
		}else{
			printf("%lld\n", N*A);
		}
	}

	return 0;
}