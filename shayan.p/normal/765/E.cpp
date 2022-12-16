// Mikaeel_noob_e_sag_e

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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int>v[maxn],vec;
int pr[maxn];
bool mark[maxn];

pii far(int u,int par=-1){
    pr[u]=par;
    pii ans={0,u};
    for(int y:v[u]){
	if(y!=par){
	    pii p=far(y,u);
	    p.F++;
	    ans=max(ans,p);
	}
    }
    return ans;
}

int dfs(int u){
    mark[u]=1;
    int bf=-1;
    for(int y:v[u]){
	if(!mark[y]){
	    int num=dfs(y);
	    if(bf!=-1 && num!=bf) cout<<-1<<endl,exit(0);
	    bf=num;
	}
    }
    return bf+1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    int A=far(1).S;
    int B=far(A).S;
    int tmp=B;
    while(tmp!=-1){
	vec.PB(tmp);
	tmp=pr[tmp];
    }
    if(sz(vec)&1){
	set<int>st;
	int u=vec[sz(vec)/2];
	mark[u]=1;
	for(int y:v[u]){
	    st.insert(dfs(y)+1);
	}
	if(sz(st)>2) return cout<<-1<<endl,0;
	int num=(*st.begin())+(*st.rbegin());
	while(!(num&1)) num>>=1;
	cout<<num<<endl;
    }
    else{
	int u=vec[sz(vec)/2],w=vec[(sz(vec)-2)/2];
	mark[u]=mark[w]=1;
	int A=dfs(u),B=dfs(w);
	cout<<A+B+1<<endl;
    }
    return 0;
}