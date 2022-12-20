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
const ll maxn=2e5+10;
const ll mod=1e9+7;

ll wh[maxn];
vector<ll>v[maxn];
bool vis[maxn];
ll ans[maxn];

int main(){
    ll n;cin>>n;
    REP(i,n){
	ll x,y;cin>>x>>y;
	x--;y--;
	v[x].PB(y);
	v[y].PB(x);
	v[2*i].PB(2*i+1);
	v[2*i+1].PB(2*i);
	wh[x]=i;
	wh[y]=-1;
    }
    REP(i,2*n){
	ll tmp=i,c=0;
	while(!vis[tmp]){
	    c=1-c;
	    vis[tmp]=1;
	    if(wh[tmp]!=-1)
		ans[wh[tmp]]=c;
	    ll num=tmp;
	    for(ll y:v[tmp]){
		if(!vis[y])
		    num=y;
	    }
	    tmp=num;
	}
    }
    REP(i,n){
	if(ans[i])
	    cout<<1<<" "<<2<<endl;
	else
	    cout<<2<<" "<<1<<endl;
    }
}