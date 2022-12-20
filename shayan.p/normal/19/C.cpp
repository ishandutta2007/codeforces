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

const ll maxn=1e5+10;
const ll P1=1e9+9,P2=1e9+7,mod=2147483647;

struct CMP{
    bool operator() (pll a,pll b){
	if((a.S-a.F)!=(b.S-b.F)) return (a.S-a.F)>(b.S-b.F);
	return a.F>b.F;
    }
};

vector<pll>eq;
map<ll,vector<ll> >mp;
ll a[maxn],hsh1[maxn],hsh2[maxn],tw1[maxn],tw2[maxn];
priority_queue<pll,vector<pll>,CMP > pq;

pll HSH(ll l,ll r){
    ll A=hsh1[r]-(l==0?0:(hsh1[l-1]*tw1[r-l+1]));
    ll B=hsh2[r]-(l==0?0:(hsh2[l-1]*tw2[r-l+1]));
    return {((A%mod)+mod)%mod,((B%mod)+mod)%mod};
}

int main(){
    ll n;cin>>n;
    tw1[0]=tw2[0]=1;
    FOR(i,1,maxn-1){
	tw1[i]=(tw1[i-1]*P1)%mod;
	tw2[i]=(tw2[i-1]*P2)%mod;
    }
    REP(i,n){
	cin>>a[i];
	hsh1[i]=((i==0?0:(hsh1[i-1]*P1))+a[i]+1)%mod;
	hsh2[i]=((i==0?0:(hsh2[i-1]*P2))+a[i]+1)%mod;
     	vector<ll>&vec=mp[a[i]];
	for(ll ind:vec){
	    ll st2=ind+1,en2=i,en1=ind,st1=en1-en2+st2;
	    if(st1>=0 && HSH(st1,en1)==HSH(st2,en2))
		pq.push({st1,en1});
	}
	mp[a[i]].PB(i);
    }
    ll lst=0;
    while(sz(pq)){
	pll p=pq.top();
	pq.pop();
	if(p.F<lst)continue;
	lst=p.S+1;
    }
    cout<<(n-lst)<<endl;
    FOR(i,lst,n-1){
	cout<<a[i]<<" ";
    }
}