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
#define FORK(i,a,b,c) for(int i=int(a);i<=b;i+=c)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1e7+10;
const ll mod=1e9+7;

int par[maxn],cnt[maxn],isol;
ll cg[maxn],ans1,ans2,ans3;

inline ll C2(ll x){
    return (x*(x-1))/2;
}

int main(){
    int n;cin>>n;
    isol=1;
    par[1]=maxn-1;
    FOR(i,2,n){
	if(par[i]==0){
	    if((2*i)>n){
		isol++;
		par[i]=maxn-1;
		continue;
	    }
	    FORK(j,i,n,i){
		if(par[j]==0)
		    par[j]=i;
	    }
	}
    }
    FOR(i,2,n){
	cnt[par[i]]++;
    }
    FOR(i,2,n){
	cnt[i]+=cnt[i-1];
    }    
    FORD(i,n,1){
	cg[i]=C2(n/i);
	FOR(j,2,n/i){
	    cg[i]-=cg[i*j];
	}
    }

    ans1=C2(n)-cg[1];
    FOR(i,2,n){
	if(par[i]==(maxn-1))continue;
	ans3-=((ll(par[i])*ll(par[i]))>n);
	ans3+=cnt[n]-cnt[n/par[i]];
    }
    ans3/=2;
    ans2=C2(n-isol)-ans1-ans3;

    cout<<ans1+2*ans2+3*ans3;
}