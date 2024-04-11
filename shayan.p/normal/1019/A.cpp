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
const ll maxn=3010;
const ll mod=1e9+7;

priority_queue<ll,vector<ll>,greater<ll> >pq;
vector<ll>v[maxn];

int main(){
    ll n,m;cin>>n>>m;
    FOR(i,1,n){
	ll p,c;cin>>p>>c;
	v[p].PB(c);
    }
    FOR(i,1,m){
	sort(v[i].begin(),v[i].end(),greater<ll>());
    }
    ll ans=inf;
    FOR(w,1,n){
	ll cnt=sz(v[1]),num=0;
	FOR(i,2,m){
	    REP(j,sz(v[i])){
		if(j>=(w-1))
		    cnt++,num+=v[i][j];
		else
		    pq.push(v[i][j]);
	    }
	}
	while(cnt<w){
	    ll x=pq.top();
	    pq.pop();
	    num+=x;
	    cnt++;
	}
	while(sz(pq)){
	    pq.pop();
	}
	ans=min(ans,num);
    }
    cout<<ans;
}