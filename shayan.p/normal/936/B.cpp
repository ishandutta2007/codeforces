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
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll mod=1e9+7;
const ll maxn=1e5+10;

int mark[maxn];
ll lo[maxn],wi[maxn];
vector<ll>rev[maxn],v[maxn];
stack<ll>st;

void dfs(ll u,bool state){
	REP(i,sz(rev[u])){
		ll y=rev[u][i];
		if(state){
			if(lo[y]==0){
				lo[y]=u;
				dfs(y,0);
			}
		}
		else{
			if(wi[y]==0){
				wi[y]=u;
				dfs(y,1);
			}
		}
	}
}

bool cycle(ll u){
	if(mark[u]==1)
		return 1;
	if(mark[u]==2)
		return 0;
	mark[u]=1;
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(cycle(y))
			return 1;
	}
	mark[u]=2;
	return 0;
}

int main(){
	ll n,m;
	cin>>n>>m;
	FOR(i,1,n){
		ll c;cin>>c;
		if(c==0){
			st.push(i);
			lo[i]=-1;
		}
		REP(j,c){
			ll x;cin>>x;
			rev[x].PB(i);
			v[i].PB(x);
		}
	}
	while(sz(st)){
		dfs(st.top(),0);
		st.pop();
	}
	ll s;cin>>s;
	if(wi[s]!=0){
		cout<<"Win\n";
		ll tmp=s,state=1;
		while(tmp!=-1){
			cout<<tmp<<" ";
			tmp=(state?wi[tmp]:lo[tmp]);
			state=1-state;
		}
	}
	else if(cycle(s)){
		cout<<"Draw";
	}
	else{
		cout<<"Lose";
	}
}