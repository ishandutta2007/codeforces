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

const int maxn=1e5+10,Max=5e6+10,maxd=53;

vector<int>v[Max],vec,vert;
vector<pii>ed;
string str[maxn];
int col[Max],C,dp[Max];
bool mark[Max],is[maxn];
int d;

void dfs1(int u){
    mark[u]=1;
    for(int y:v[u]){
	if(!mark[y])
	    dfs1(y);
    }
    vec.PB(u);
}
void dfs2(int u){
    mark[u]=1;col[u]=C;
    if(str[u/d][u%d]=='1' && is[u/d]==0) dp[C]++,is[u/d]=1,vert.PB(u/d);
    for(int y:v[u]){
	if(!mark[y])
	    dfs2(y);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m>>d;
    for(int i=0;i<m;i++){
	int a,b;cin>>a>>b;
	ed.PB({--a,--b});
	for(int j=0;j<d;j++){
	    int A=a*d+j,B=b*d+((j+1)%d);
	    v[A].PB(B);
	}
    }
    for(int i=0;i<n;i++){
	cin>>str[i];
    }
    for(int i=0;i<n*d;i++){
	if(!mark[i])
	    dfs1(i);
    }
    for(int i=0;i<Max;i++){
	v[i].clear();
    }
    for(pii p:ed){
	for(int j=0;j<d;j++){
	    int A=p.F*d+j,B=p.S*d+((j+1)%d);
	    v[B].PB(A);
	}
    }
    memset(mark,0,sizeof mark);
    reverse(vec.begin(),vec.end());
    for(int x:vec){
	if(!mark[x]){
	    for(int y:vert)
		is[y]=0;
	    vert.clear();
	    dfs2(x),C++;
	}
    }
    for(int i=0;i<Max;i++){
	v[i].clear();
    }
    for(pii p:ed){
	for(int j=0;j<d;j++){
	    int A=p.F*d+j,B=p.S*d+((j+1)%d);
	    if(col[A]!=col[B])
		v[col[A]].PB(col[B]);
	}
    }
    for(int i=C-1;i>=0;i--){
	int Num=0;
	for(int y:v[i]){
	    Num=max(Num,dp[y]);
	}
	dp[i]+=Num;
    }
    return cout<<dp[col[0]]<<endl,0;
}