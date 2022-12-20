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
const ll maxn=1e6+10;
const ll mod=1e9+7;

ll f[maxn],ans=1;
bool vis[maxn];

int main(){
    ll p,k;cin>>p>>k;
    if(k==0){
	FOR(i,1,p-1){
	    ans=(ans*p)%mod;
	}
	cout<<ans;
	return 0;
    }
    REP(i,p){
	f[(k*i)%p]=i;
    }
    REP(i,p){
	ll tmp=i,num=1;
	if(!vis[i]){
	    while(!vis[tmp]){
		num=(num*k)%p;
		vis[tmp]=1;
		tmp=f[tmp];
	    }
	    if(num==1)
		ans=(ans*p)%mod;
	}
    }
    cout<<ans;
}