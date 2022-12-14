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

ll N, M, K;
deque<ll> v;


int main(){
	scanf("%lld%lld%lld", &N, &M, &K);
	for(int i=0; i<(int)M; i++){
		ll x;
		scanf("%lld", &x);
		v.pb(x);
	}
	int ans = 0;
	ll T = K;
	ll cnt = 0;
	while(!v.empty()){
		cnt = 0;
		if(T<v.front()){
			ll x = (v.front() - T) / K;
			T += x * K;
			if(T<v.front())	T+=K;
		}
		while(!v.empty() && v.front()<=T){
			v.pop_front(); cnt++;
		}
		T+=cnt;
		ans++;
	}
	cout<<ans;

	return 0;
}