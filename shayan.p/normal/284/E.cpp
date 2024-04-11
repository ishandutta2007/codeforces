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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=302;
const ll MAX=1e5+2;
const ll mod=1e9+7;
const ll BIG=3e7+10;

vector<ll>v[maxn];
ll f[maxn],t,finish[maxn];
bool mark[maxn];
ll a[maxn];

void topol_sort(ll u){
	mark[u]=1;
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(!mark[y]){
			topol_sort(y);
		}
	}
	f[t]=u;
	finish[u]=t;
	t++;
}

bool cycle_detect(ll u){
	mark[u]=1;
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(finish[y]>finish[u])
			return 1;
		if(!mark[y]){
			if(cycle_detect(y))
				return 1;
		}
	}
	return 0;
}

void dfs(ll u){
	mark[u]=1;
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(!mark[y]){
			a[y]+=a[u];
			
			if(a[y]>=BIG){// in order to avoid overflow
			// if a[y] becomes more than BIG it means that one of its parents is now more than 1e5 
			//and since we have to use all of the parents the answer would be 0
				cout<<0;
				exit(0);
			}
			
			dfs(y);
		}
	}
}

ll dp[maxn][MAX];
set<ll>strict;// used to make strictly greater to greater

int main(){
	ll n,m,t;cin>>n>>m>>t;
	REP(i,n)
		cin>>a[i];
	REP(i,m){
		ll A,B;cin>>A>>B;
		A--;B--;
		v[A].PB(B);
		strict.insert(A);
	}
	REP(i,n)
		if(!mark[i])
			topol_sort(i);
			
	memset(mark,0,sizeof mark);
	
	REP(i,n)
		if(!mark[i])
			if(cycle_detect(i)){
				cout<<0;
				return 0;
			}
			
	memset(mark,0,sizeof mark);
	
	REPD(i,n)
		if(!mark[f[i]])
			dfs(f[i]);
	//changing strictly greater to greater:
	for(set<ll>::iterator it=strict.begin();it!=strict.end();it++){
		t-=a[*it];
	}
	if(t<0){
		cout<<0;
		return 0;
	}
	//dp part
	dp[0][0]=1;
	
	REP(i,n){
		REP(j,MAX){
			if(j-a[i]<0)
				dp[i][j]+=(i==0?0:dp[i-1][j]);
			else
				dp[i][j]+=dp[i][j-a[i]]+(i==0?0:dp[i-1][j]);
			dp[i][j]%=mod;
		}
	}
	cout<<dp[n-1][t];
}