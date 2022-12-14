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

const int MAX_N = 100000;

ll N, L, R, QL, QR;
vector<ll> v;
ll ans = INFLL;

int main(){
	ll sumL=0, sumR=0;
	scanf("%lld%lld%lld%lld%lld", &N, &L, &R, &QL, &QR);
	for(int i=1; i<=N; i++){
		ll x;
		scanf("%lld", &x);
		v.pb(x);
		sumR+=x;
	} 
	for(int i=0; i<=N; i++){
		int cntL = i, cntR = N-i;
		ll sum = L * sumL + R * sumR;
		if(cntL>cntR){
			sum += (QL * (cntL-cntR-1));
		}else if(cntR>cntL){
			sum += QR * (cntR-cntL-1);
		}
		//cout<<i<<" "<<sumL<<" "<<sumR<<" "<<sum<<endl;
		ans = min(ans, sum);
		if(i==N)	break;
		sumL += v[i]; sumR -= v[i];
	}
	cout<<ans;
	return 0;
}