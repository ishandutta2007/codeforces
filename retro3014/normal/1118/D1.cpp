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

const int MAX_N = 200000;

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
ll M, SUM;
vector<ll> v;
ll sum[MAX_N+1];

bool chk(ll x){
	ll S = 0;
	ll s = 0, e = v.size()-1, m;
	while(s<e){
		m = (s+e)/2+1;
		if(v[m] > (m/x))	s = m;
		else	e = m-1;
	}
	//cout<<m<<endl;
	ll k = m/x - 1;
	if((m/x)==0){
		S = sum[m];
	}else{
		S = sum[m] - (x * k * (k+1)) / 2;
		S -= (m - (k+1)*x + 1) * (k+1);
	}
	//printf("%lld %lld\n", x, S);
	return (S>=M);
}

bool sf(ll x, ll y){
	return x>y;
}

int main(){
	scanf("%d%lld", &N, &M);
	for(int i=0; i<N; i++){
		ll x; scanf("%lld", &x); v.push_back(x);
		SUM+=x;
	}
	sort(v.begin(), v.end(), sf);
	for(int i=0; i<N; i++){
		if(i==0)	sum[i] = v[i];
		else sum[i] = sum[i-1] + v[i];
	}
	if(SUM<M)	{
		printf("-1"); return 0;
	}
	ll s = 1, e = N, m;
	while(s<e){
		m = (s+e)/2;
		if(chk(m))	e = m;
		else	s = m+1;
	}
	printf("%lld", s);
	return 0;
}