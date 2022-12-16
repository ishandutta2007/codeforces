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

#pragma GCC Optimize("Ofast")

ll cnt[10],a[10],fac[20],ans;

void go(ll u,ll x){
    if(u==10){
	ll sm=0;
	REP(i,10){
	    sm+=a[i];
	    if(cnt[i]!=0&&a[i]==0)
		return;
	}
	ll x=0;
	ll num=fac[sm];
	REP(i,10){
	    num/=fac[a[i]];
	}
	x+=num;
	num*=a[0];
	num/=sm;
	x-=num;
	ans+=x;
	return;
    }
    if(x>cnt[u]){
	return;
    }
    a[u]=x;
    go(u+1,0);
    go(u,x+1);
}

int main(){
    fac[0]=1;
    FOR(i,1,19)
	fac[i]=i*fac[i-1];
    
    ll x;cin>>x;
    while(x>0){
	cnt[x%10]++;
	x/=10;
    }
    go(0,0);
    cout<<ans;
}