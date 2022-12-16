// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=1e5+10;
const ll mod=1e9+7;
const ll Big=1e10+10;
const double eps=0.00001;

ll a[maxn],b[maxn],n,p;

bool pos(double t){
	double tot=0;
	REP(i,n){
		if(b[i]-(t*double(a[i]))<0)
			tot+=(t*double(a[i]))-b[i];
	}
	if(tot<=p*t)return 1;
	return 0;
}

int main(){
	cin>>n>>p;
	ll sum=0;
	REP(i,n){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	if(sum<=p){
		cout<<-1;
		return 0;
	}
	double l=0,r=Big;
	double ans=-1;
	while((r-l)>=eps){
		double mid=(l+r)/2;
		if(pos(mid)){
			ans=mid;
			l=mid;
		}
		else{
			r=mid;
		}
	}
	if(ans==-1)cout<<-1;

	else cout<<setprecision(6)<<fixed<<ans;
}