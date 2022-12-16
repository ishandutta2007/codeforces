// Wanna Hack? GL...

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

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int> v[maxn];
vector<int> cycle[maxn],vec;
bool mark[maxn];
int par[maxn],h[maxn],CNT;

pii far(int u){
    mark[u]=1;
    pii ans={1,u};
    for(int y:v[u]){
	if(mark[y]==0){
	    par[y]=u;
	    pii p=far(y);
	    p.F++;
	    ans=max(ans,p);
	}
    }
    return ans;
}

void Push(int a,int b,vector<int>&vec){
    while(a!=b){
	a=par[a];
	vec.PB(a);
    }
}

void dfs(int u){
    mark[u]=1;
    bool leaf=1;
    for(int y:v[u]){
	if(mark[y]==0){
	    leaf=0;
	    h[y]=h[u]+1;
	    par[y]=u;
	    dfs(y);
	}
    }
    if(leaf && (--CNT)>=0){
	vec.clear();
	for(int y:v[u]){
	    if(h[u]-h[y]>1 && sz(vec)<2)
		vec.PB(y);
	}
	int A=vec[0],B=vec[1];
	if(h[A]<h[B]) swap(A,B);
	int ln1=h[u]-h[A],ln2=h[u]-h[B];
	cycle[CNT].PB(u);
	if(ln1%3!=2){
	    Push(u,A,cycle[CNT]);
	}
	else if(ln2%3!=2){
	    Push(u,B,cycle[CNT]);
	}
	else{
	    cycle[CNT].PB(A);
	    Push(A,B,cycle[CNT]);
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    for(int i=0;i<m;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    memset(mark,0,sizeof mark);
    int A=far(1).S;
    memset(mark,0,sizeof mark);
    pii pp=far(A);
    if(1ll*pp.F*k>=n){
	cout<<"PATH\n"<<pp.F<<"\n";
	int tmp=pp.S;
	while(tmp!=A){
	    cout<<tmp<<" ";
	    tmp=par[tmp];
	}
	cout<<A<<"\n";
	return 0;
    }
    cout<<"CYCLES\n";
    memset(mark,0,sizeof mark);
    CNT=k;
    dfs(1);
    for(int i=0;i<k;i++){
	cout<<sz(cycle[i])<<"\n";
	for(int x:cycle[i])
	    cout<<x<<" ";
	cout<<"\n";
    }
    return 0;
}