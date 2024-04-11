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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

bool mark[maxn],is[maxn];
vector<int>v[maxn],g[maxn],ans;
bool OR;
int la,lb;

void add_edge(int a,int b){
    la=a;
    lb=b;
    g[a].PB(b);
    g[b].PB(a);
}

void check(int u){
    OR|=is[u];
    mark[u]=1;
    for(int y:v[u]){
	if(!mark[y])
	    check(y);
    }
}

bool put(int u){
    mark[u]=1;
    bool IS=is[u];
    for(int y:v[u]){
	if(!mark[y]){
	    bool bl=put(y);
	    IS^=bl;
	    if(bl)
		add_edge(y,u);
	    else
		add_edge(y,u),add_edge(y,u);
	}
    }
    return IS;
}

void solve(int u){
    vector<int>vec;
    while(sz(g[u])){
	int U=g[u].back();
	vec.PB(U);
	g[u].pop_back();
	u=U;
    }
    for(int y:vec){
	ans.PB(y);
	solve(y);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    for(int i=1;i<=n;i++){
	cin>>is[i];
    }
    int r=-1;
    for(int i=1;i<=n;i++){
	if(!mark[i]){
	    OR=0;
	    check(i);
	    if(OR){
		if(r==-1)
		    r=i;
		else
		    return cout<<-1<<endl,0;
	    }
	}
    }
    if(r==-1){
	return cout<<0<<endl,0;
    }
    memset(mark,0,sizeof mark);
    if(put(r)){
	g[0].PB(r);
	g[r].PB(0);
    }
    else{
	g[la].pop_back();
	g[la].PB(0);
	g[0].PB(lb);
    }
    solve(0);
    cout<<sz(ans)-1<<"\n";
    for(int i=0;i<sz(ans)-1;i++){
	cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}