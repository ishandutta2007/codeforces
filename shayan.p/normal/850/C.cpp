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

map<ll,ll>mp,dp;
bool arr[32];

ll calc(ll x){
    if(x==0)return 0;
    if(dp.count(x))return dp[x];
    ll lst=-1;
    REP(i,31){
	if(bit(x,i))
	    lst=i;
    }
    FOR(i,1,lst+1){
	calc((x&((1<<(i-1))-1))|(x>>i));
    }
    memset(arr,0,sizeof arr);
    FOR(i,1,lst+1){
	arr[dp[(x&((1<<(i-1))-1))|(x>>i)]]=1;
    }
    REP(i,31){
	if(!arr[i]){
	    dp[x]=i;
	    break;
	}
    }
    return dp[x];
}

int main(){
    ll n;cin>>n;
    REP(i,n){
	ll x;cin>>x;
	for(ll p=2;(p*p)<=x;p++){
	    ll cnt=0;
	    while(x%p==0){
		x/=p;
		cnt++;
	    }
	    if(cnt>0)
		mp[p]|=(1<<(cnt-1));
	}
	if(x!=1)
	    mp[x]|=1;
    }
    ll ans=0;
    for(pll pr:mp){
	ll msk=pr.S;
	ans^=calc(msk);
    }
    cout<<(ans==0?"Arpa":"Mojtaba");
}