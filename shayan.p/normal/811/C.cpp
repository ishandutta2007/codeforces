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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=5010;

ll Xor[maxn][maxn];
ll a[maxn];
ll beg[maxn],en[maxn];
ll seg[maxn];
ll val[maxn];
ll ans;

int mark[maxn];//0: not seen / 1:seen once and its ans has been sumed up 2:seen more than once so its not a root and its ans is not sumed up
vector<ll>v[maxn];
ll Ans[maxn];

ll dfs(ll u){
	if(mark[u]==2){
		return Ans[u];
	}
	if(mark[u]==1){
		ans-=Ans[u];
		mark[u]=2;
		return Ans[u];
	}
	mark[u]=1;
	ll sum=0;
	REP(i,sz(v[u]))
		sum+=dfs(v[u][i]);
	return Ans[u]=max(sum,val[u]);
}
int main(){
	ll n;cin>>n;
	FOR(i,1,n)
		cin>>a[i];
	FOR(i,1,n){
		if(beg[a[i]]==0){
			beg[a[i]]=i;
		}
		en[a[i]]=i;
	}
	FOR(i,1,n){
		ll j=i,last=i,num=0;
		bool yes=1;
		set<ll>s;s.clear();
		while(j>=last){
			last=min(last,beg[a[j]]);
			if(i<en[a[j]]){
				yes=0;
				break;
			}
			if(!s.count(a[j])){
				s.insert(a[j]);
				num=num^a[j];
			}
			j--;
		}
		if(yes){
			seg[i]=last;
			val[i]=num;
			FORD(j,i-1,last){
				if(seg[j]!=0){//then segment starting from j is inside our segment
					v[i].PB(j);
					j=seg[j];
				}
			}
		}
	}
	FOR(i,1,n){
		if(!mark[i]){
			ans+=dfs(i);
		}
	}
	cout<<ans;
}