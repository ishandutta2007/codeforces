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

int N;
vector<ll> v;
ll sum;
ll ans;
int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		ll x;
		scanf("%lld", &x); v.pb(x);
		sum+=x;
	}
	ll used = 0;
	while(!v.empty()){
		ll now = v.back(); v.pop_back();
		ll tri = min(sum/3, now/2);
		ans+=tri;
		sum -= tri*3;
		used += tri*3;
		if(now>used){
			now-=used;
			used = 0;
			sum -= now;
		}else{
			used -= now;
		}
	}
	printf("%lld", ans);
	return 0;
}