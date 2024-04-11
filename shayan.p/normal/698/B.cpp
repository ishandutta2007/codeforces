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
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)
#define Bug(num) cout<<"here "<<num<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=2e5+10;
const ll mod=1e9+7;
const ll inf=4e18;

int mark[maxn];
ll LST;
ll p[maxn];
vector<ll>node;

void dfs(ll u){
	mark[u]=1;
	if(mark[p[u]]==0){
		dfs(p[u]);
	}
	else if(mark[p[u]]==1){
		LST=u;
		mark[p[u]]=2;
	}
	mark[u]=2;
}

int main(){
	ll n;cin>>n;
	FOR(i,1,n)
		cin>>p[i];
	FOR(i,1,n){
		if(!mark[i]){
			LST=-1;
			dfs(i);
			if(LST!=-1)
				node.PB(LST);
		}
	}
	ll self=-1,ans=sz(node)-1;
	REP(i,sz(node)){
		if(p[node[i]]==node[i]){
			self=i;
			break;
		}
	}
	if(self==-1){
		ans++;
		p[node[0]]=node[0];
		self=0;
	}
	REP(i,sz(node)){
		if(i!=self){
			p[node[i]]=node[self];
		}
	}
	cout<<ans<<endl;
	FOR(i,1,n)
		cout<<p[i]<<" ";
}