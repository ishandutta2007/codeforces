// Phoenix

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

const int maxn=5e5+10,inf=2e9;

priority_queue<pair<pii,int>,vector<pair<pii,int> >,greater<pair<pii,int> > > pq;

vector<pii>v[2][maxn];
int l[4*maxn],r[4*maxn],dp[4*maxn],C;

void add_edge(int a,int b,int c,int d){
    v[C&1][a].PB({b,C});
    l[C]=c+((c&1) != (C&1));
    r[C]=d-((d&1) != (C&1));
    if(l[C]>r[C]) v[C&1][a].pop_back();
    C++;
}

bool CMP(pii a,pii b){
    return l[a.S]>l[b.S];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
	int a,b,c,d;cin>>a>>b>>c>>d;
	--d;
	add_edge(a,b,c,d);
	add_edge(a,b,c,d);
	add_edge(b,a,c,d);
	add_edge(b,a,c,d);
    }
    for(int i=1;i<=n;i++){
	sort(v[0][i].begin(),v[0][i].end(),CMP);
	sort(v[1][i].begin(),v[1][i].end(),CMP);
    }
    int ANS=inf;
    l[C]=r[C]=-1;
    pq.push({{0,1},C});
    while(!pq.empty()){
	int u=pq.top().F.S,t=pq.top().F.F,id=pq.top().S,mm=t&1,mx=r[id]+1;
	if(u==n) ANS=min(ANS,t);
	pq.pop();
	while(!v[mm][u].empty() && l[v[mm][u].back().S]<=mx){
	    if(t<=r[v[mm][u].back().S]){
		int u2=v[mm][u].back().F,id2=v[mm][u].back().S;
		dp[id2]=max(t,l[id2])+1;
		pq.push({{dp[id2],u2},id2});
	    }
	    v[mm][u].pop_back();
	}
    }
    if(ANS==inf) ANS=-1;
    cout<<ANS<<"\n";
    return 0;
}