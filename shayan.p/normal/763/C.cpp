// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

ll a[maxn],n,m;
set<ll>st;

ll rev(ll x,ll md){
    ll t=md-2,an=1;
    while(t>0){
	if(t%2) an=(an*x)%md;
	x=(x*x)%md;
	t/=2;
    }
    return an;
}

pll solve2(){
    REP(i,n){
	st.insert(a[i]);
    }
    ll dl=(a[1]-a[0]+m)%m;
    ll cof=n;
    REP(i,n){
	cof-=st.count((a[i]+dl)%m);
    }
    ll d=(dl*rev(cof,m))%m;
    ll x=a[0];
    st.erase(x);
    while(st.count((x+d)%m)){
	x=(x+d)%m;
	st.erase(x);
    }
    x=a[0];
    while(st.count((x-d+m)%m)){
	x=(x-d+m)%m;
	st.erase(x);
    }
    
    if(sz(st)==0)
	return MP(x,d);
    else
	return MP(-1,-1);
}

pll solve1(){
    REP(i,m){
	st.insert(i);
    }
    REP(i,n){
	st.erase(a[i]);
    }
    n=m-n;
    ll h=0;
    REP(i,m){
	if(st.count(i))
	    a[h++]=i;
    }
    st.clear();
    pll p=solve2();
    if(p.F==-1)
	return MP(-1,-1);
    else
	return MP((p.F-p.S+m)%m,m-p.S);
}

int main(){
    cin>>m>>n;
    REP(i,n){
	cin>>a[i];
    }
    if((n==1)||(m==2)||(n==m)){
	cout<<a[0]<<" "<<1;
	return 0;
    }
    pll ans;
    if(m<(2*n))
	ans=solve1();
    else
	ans=solve2();
    
    if(ans.F==-1)
	cout<<-1;
    else
	cout<<ans.F<<" "<<ans.S;
}