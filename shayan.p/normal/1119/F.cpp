// Faster!

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=25e4+10;
const ll inf=1e16;

struct Set{
    set<pair<ll,int> >st,st2;
    vector<pair<bool,pair<ll,int> > >rec;
    ll sum=0;
    void record(){
	rec.clear();
    }
    void restart(){
	for(int i=sz(rec)-1;i>=0;i--){
	    if(rec[i].F) st.erase(rec[i].S),sum-=rec[i].S.F;
	    else         st.insert(rec[i].S),sum+=rec[i].S.F;
	}
    }
    void add(pair<ll,int> x){
	if(x.F<=0) return;
	rec.PB({1,x});
	st.insert(x);
	sum+=x.F;
    }
    void era(pair<ll,int> x){
	if(st.count(x)==0){
	    st2.erase(x);
	    return;
	}
	rec.PB({0,x});
	st.erase(x);
	sum-=x.F;
    }
    void balance(int n){
	while(sz(st)>n){
	    era(*st.begin());
	}
    }
    void _balance(int n){
	while(sz(st)>n){
	    st2.insert(*st.begin());
	    sum-= st.begin()->F;
	    st.erase(st.begin());
	}
	while(sz(st)<n && sz(st2)){
	    st.insert(*st2.rbegin());
	    sum+= st2.rbegin()->F;
	    st2.erase(*st2.rbegin());
	}
    } 
};Set st[maxn];

ll dp[2][maxn],total[maxn],ans[maxn];
bool in[maxn];
int ids[maxn],mark[maxn],mrk;
vector<pii>g[maxn],v[maxn];

void dfs(int u,int k){
    mark[u]=mrk;
    st[u]._balance(k);
    st[u].record();
    dp[0][u]=total[u];
    for(pii p:v[u]){
	if(mark[p.F]!=mrk){
	    dfs(p.F,k);
	    st[u].add({dp[0][p.F]+p.S-dp[1][p.F], -p.F-10});
	    dp[0][u]+=dp[0][p.F];
	}
	else{
	    dp[0][u]-=p.S;
	}
    }
    st[u].balance(k);
    dp[1][u]=dp[0][u];
    dp[0][u]-=st[u].sum;
    if(k>0) st[u].balance(k-1), dp[1][u]-=st[u].sum;
    else dp[1][u]=inf;
    st[u].restart();
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
	int a,b,c;cin>>a>>b>>c;
	--a,--b;
	g[a].PB({b,c});
	g[b].PB({a,c});
	st[a].add({c,b});
	st[b].add({c,a});
	total[a]+=c;
	total[b]+=c;
    }
    for(int i=0;i<n;i++){
	ids[i]=i;
    }
    sort(ids,ids+n,[](int a,int b){ return sz(g[a])>sz(g[b]); });
    int pt=0;
    for(int i=n-1;i>=0;i--){
	while(pt<n && sz(g[ids[pt]])>i){
	    int u=ids[pt++];
	    for(pii p:g[u]){
		if(in[p.F]){
		    v[p.F].PB({u,p.S});
		    v[u].PB(p);
		    st[u].era({p.S,p.F});
		    st[p.F].era({p.S,u});
		}
	    }
	    in[u]=1;
	}
	++mrk;
	for(int j=0;j<pt;j++){
	    if(mark[ids[j]]!=mrk)
		dfs(ids[j],i),ans[i]+=dp[0][ids[j]];
	}
    }
    for(int i=0;i<n;i++){
	cout<<ans[i]<<" ";
    }
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.