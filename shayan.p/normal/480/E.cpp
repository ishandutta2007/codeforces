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

#define Bug(tag) cerr<<"here "<<tag<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=2e3+10;

set<ll>ff[maxn];
string grid[maxn];
pll p[maxn];
ll Ans[maxn];
ll n,m,k;

ll dp[maxn][maxn];

ll find_ans(){
	REP(i,m)
		dp[0][i]=(grid[0][i]=='X'?0:1);
	REP(i,n)
		dp[i][0]=(grid[i][0]=='X'?0:1);
	
	FOR(i,1,n-1){
		FOR(j,1,m-1){
			if(grid[i][j]=='X')
				dp[i][j]=0;
			else if(dp[i][j-1]!=dp[i-1][j]){
				dp[i][j]=min(dp[i][j-1],dp[i-1][j])+1;
			}
			else{
				ll num=dp[i][j-1];
				dp[i][j]=num+(grid[i-num][j-num]!='X');
			}
		}
	}
	ll mx=0;
	REP(i,n)
		REP(j,m)
			mx=max(mx,dp[i][j]);
	return mx;
}

bool check(ll x,ll y,ll Sz){
	multiset<ll>L,R;L.clear();R.clear();
	L.insert(-1);R.insert(m);
	ll st=max(ll(0),x-Sz+1);
	
	REP(i,Sz){
		set<ll>::iterator it=ff[st+i].upper_bound(y);
		if(it!=ff[st+i].end())
			R.insert(*it);
		if(it!=ff[st+i].begin())
			L.insert(*(--it));
	}
	while((st+Sz-1)<n){
		ll l=*L.rbegin(),r=*R.begin();	
		if((r-l-1)>=Sz)
			return 1;
		// some removing and adding
		set<ll>::iterator it;
		it=ff[st].upper_bound(y);
		if(it!=ff[st].end()){
			set<ll>::iterator it2=R.find(*it);
			if(it2!=R.end())
				R.erase(it2);
		}
		if(it!=ff[st].begin()){
			set<ll>::iterator it2=L.find(*(--it));
			if(it2!=L.end())
				L.erase(it2);
		}
		ll num=st+Sz;
		if(num==n)
			break;
		it=ff[num].upper_bound(y);
		if(it!=ff[num].end())
			R.insert(*it);
		if(it!=ff[num].begin())
			L.insert(*(--it));	
		st++;
	}
	return 0;
}

int main(){
	cin>>n>>m>>k;
	REP(i,n)
		cin>>grid[i];
	REP(i,n){
		REP(j,m){
			if(grid[i][j]=='X'){
				ff[i].insert(j);
			}
		}
	}
	REP(i,k){
		cin>>p[i].F>>p[i].S;
		p[i].F--;p[i].S--;
		ff[p[i].F].insert(p[i].S);
		grid[p[i].F][p[i].S]='X';
	}
	ll ans=Ans[k]=find_ans();
	ll Mi=min(m,n);
	
	REPD(i,k){
		ll x=p[i].F,y=p[i].S;
		ff[x].erase(y);
		ll tmp=ans;
		FOR(j,ans+1,Mi){
			if(check(x,y,j))
				tmp=j;
			else
				break;
		}
		ans=tmp;
		Ans[i]=ans;
		
	}
	
	FOR(i,1,k)
		cout<<Ans[i]<<endl;
}