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
typedef pair<int,double> pid;

const int maxn=810,Source=maxn-3,Sink=maxn-2,inf=1e9;
const double eps=1e-10;

vector<pair<int,pid> >v[maxn];
vector<int>vid[maxn];
pii p[maxn];

void add_edge(int a,int b,int c,double d){
    vid[a].PB(sz(v[b]));
    vid[b].PB(sz(v[a]));
    v[a].PB({b,{c,d}});
    v[b].PB({a,{0,-d}});
}

int arr[maxn],pt[maxn],par[maxn];
bool inq[maxn];
double dis[maxn];

bool spfa(int Source,int Sink){
    int L=0,R=0;
    fill(dis,dis+maxn,inf);memset(par,-1,sizeof par);memset(inq,0,sizeof inq);    
    arr[R++]=Source;dis[Source]=0;inq[Source]=1;
    while(L!=R){
	int u=arr[L++]; if(L==maxn) L=0;
	inq[u]=0;
	for(int i=0;i<sz(v[u]);i++){
	    int y=v[u][i].F,w=v[u][i].S.F;
	    double c=v[u][i].S.S;
	    if(w>0 && dis[u]+c<dis[y]){
		dis[y]=dis[u]+c,par[y]=u;
		if(!inq[y]) inq[y]=1,arr[R++]=y;
		if(R==maxn) R=0;
	    }
	}
    }
    return par[Sink]!=-1;
}

pid dfs(int u,int Sink,int flw){
    if(u==Sink) return {flw,0};
    pid ans={0,0};
    while(pt[u]<sz(v[u])){
	int y=v[u][pt[u]].F,&w=v[u][pt[u]].S.F,&w2=v[y][vid[u][pt[u]]].S.F;
	double c=v[u][pt[u]].S.S;
	if(w>0 && par[y]==u){
	    pid num=dfs(y,Sink,min(w,flw-ans.F));
	    ans.F+=num.F;
	    ans.S+=num.S+c*num.F;
	    w-=num.F;w2+=num.F;
	}
	if(ans.F==flw) break;
	pt[u]++;
    }
    return ans;
}

pid Flow(int Source,int Sink){
    pid ans={0,0};
    while(spfa(Source,Sink)){
	memset(pt,0,sizeof pt);
	pid num=dfs(Source,Sink,inf);
	ans={ans.F+num.F,ans.S+num.S};
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++)
	cin>>p[i].S>>p[i].F;
    for(int i=0;i<n;i++){
	add_edge(Source,2*i,2,0);
	add_edge(2*i+1,Sink,1,0);
	for(int j=0;j<n;j++){
	    if(p[i].F>p[j].F){
		auto T=[](ll X){return X*X;};
		add_edge(2*i,2*j+1,1,sqrt(T(p[i].F-p[j].F)+T(p[i].S-p[j].S)));
	    }
	}
    }
    pid ans=Flow(Source,Sink);
    if(ans.F<n-1) cout<<-1<<endl;
    else cout<<setprecision(10)<<fixed<<ans.S<<endl;
    return 0;
}