// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) ((c).size())
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
#define all(s) s.begin(),s.end()
#pragma GCC optimize("Ofast")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll inf=1e18;
const ll maxn=1e5+10;
const ll maxw=3e5+10;

vector<ll>v1,v2,v3;
ll sm1[maxn],sm2[maxn];

int main(){
	ll n,m;cin>>n>>m;
	REP(i,n){
		ll act,c;cin>>act>>c;
		if(act==1)v1.PB(c);
		if(act==2)v2.PB(c);
		if(act==3)v3.PB(c);
	}
	sort(all(v1),greater<ll>());
	sort(all(v2),greater<ll>());
	sort(all(v3),greater<ll>());
	vector<ll>case1,case2;
	ll Big=0;
	if(sz(v1))Big=v1[0];
	for(ll i=1;i<sz(v1);i+=2){//fard ta bardarim
		if(i+1==sz(v1))continue;
		case1.PB(v1[i]+v1[i+1]);
	}
	for(ll i=0;i<sz(v1);i+=2){//zoj ta bardarim
		if(i+1==sz(v1))continue;
		case2.PB(v1[i]+v1[i+1]);
	}
	REP(i,sz(v2)){
		case1.PB(v2[i]);
		case2.PB(v2[i]);
	}
	sort(all(case1),greater<ll>());
	sort(all(case2),greater<ll>());
	FOR(i,1,sz(case1)){
		sm1[i]=sm1[i-1]+case1[i-1];
	}
	FOR(i,1,sz(case2)){
		sm2[i]=sm2[i-1]+case2[i-1];
	}
	ll sum=0,Ans=0;
	ll Sz=sz(v3);
	FOR(i,0,min((m/3),Sz)){
		ll cap=m-(3*i);
		ll t1=((cap-1)/2);
		ll t2=(cap/2);
		ll ans1=Big;
		ll num1=sz(case1),num2=sz(case2);
		if(num1&&t1>=0)ans1+=sm1[min(t1,num1)];
		ll ans2=0;
		if(num2&&t2>=0)ans2+=sm2[min(t2,num2)];
		ll ans=max(ans1,ans2)+sum;
		if(cap==0)ans=sum;
		Ans=max(ans,Ans);
		if(i==sz(v3))break;
		sum+=v3[i];
	}
	cout<<Ans;
}