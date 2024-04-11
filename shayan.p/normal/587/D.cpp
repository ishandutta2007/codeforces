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

const int maxn=1e6+10,mod=1e9+7;
const ll inf=1e18;

int n,m,C,Col;
int col[maxn];
bool mark[maxn],is[maxn];
pii p[maxn];// w // id
vector<int>g[maxn];// to who id
map<int,vector<int> >mp[maxn];

vector<int>v[maxn],vv[maxn],stk;

void add_edge(int a,int b){
    v[a^1].PB(b);
    v[b^1].PB(a);
    vv[b].PB(a^1);
    vv[a].PB(b^1);
}

void Do(vector<int>&vec){
    int start=C;
    for(int id:vec)
	add_edge(id^1,C),C+=2;
    for(int i=start+2;i<C;i+=2)
	add_edge((i-2)^1,i);
    for(int i=1;i<sz(vec);i++)
	add_edge(vec[i]^1,(start+(2*i)-2)^1);
}

void No(int id,bool ys){
    if(ys) v[id].PB(id^1),vv[id^1].PB(id);
    else v[id].pop_back(),vv[id^1].pop_back();
}

void dfs(int u,bool ys){
    col[u]=Col;
    mark[u]=1;
    for(int y:(ys?vv[u]:v[u]))
	if(!mark[y])
	    dfs(y,ys);
    if(!ys) stk.PB(u);
}

bool check(){
    stk.clear();Col=0;
    memset(mark,0,sizeof mark);
    for(int i=0;i<C;i++) if(!mark[i]) dfs(i,0);
    memset(mark,0,sizeof mark);
    for(int i=C-1;i>=0;i--) if(!mark[stk[i]]) dfs(stk[i],1),Col++;
    for(int i=0;i<C;i+=2) if(col[i]==col[i^1]) return 0;
    for(int i=0;i<C;i+=2) is[i>>1]=col[i]>col[i^1];
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
	int a,b,c,t;cin>>a>>b>>c>>t;
	g[a].PB(2*i);
	g[b].PB(2*i);
	mp[a][c].PB(2*i+1);
	mp[b][c].PB(2*i+1);
	p[i]={t,i};
    }
    C=2*m;

    for(int i=1;i<=n;i++)
	Do(g[i]);
    for(int i=1;i<=n;i++)
	for(auto x:mp[i])
	    Do(x.S);
    sort(p,p+m);
    int l=0,r=m,ans=-1;
    
    while(l<=r){
	int mid=(l+r)>>1;
	for(int i=mid;i<m;i++)
	    No(2*p[i].S,1);
	if(check())
	    ans=mid,r=mid-1;
	else
	    l=mid+1;
	for(int i=mid;i<m;i++)
	    No(2*p[i].S,0);
    }
    if(ans==-1)
    return cout<<"No\n",0;
    cout<<"Yes\n";
    for(int i=ans;i<m;i++)
	No(2*p[i].S,1);
    check();
    vector<int>Ans;
    for(int i=0;i<m;i++){
	if(is[i])
	    Ans.PB(i);
    }
    if(ans==0)
	cout<<0<<" "<<0<<"\n";
    else
	cout<<p[ans-1].F<<" "<<sz(Ans)<<"\n";
    for(int e:Ans)
	cout<<e+1<<" ";
    cout<<"\n";
    return 0;
}