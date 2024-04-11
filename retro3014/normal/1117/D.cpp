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

const ll DIV = 1000000007;

ll N, M;
set<ll> st;
map<ll, ll> mp;

ll ans(ll x){
	if(x<0)	return 0;
	if(st.find(x)!=st.end())	return mp[x];
	ll L = x/2, R = x/2;
	if(x%2==0)	R--;
	ll k = 0;
	k = ((ans(L) * ans(R))%DIV);
	for(ll i=0; i<M; i++){
		k = (k + ((ans(L-i) * ans(R-(M-i-1))%DIV)))%DIV;
	}
	st.insert(x); mp[x] = k;
	return k;
}

int main(){
	scanf("%lld%lld", &N, &M);
	for(ll i=0; i<M; i++){
		mp[i] = 1; st.insert(i);
	}
	printf("%lld", ans(N));
	return 0;
}