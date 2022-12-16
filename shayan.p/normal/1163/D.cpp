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

const int maxn=110,inf=5e8;

int nxt[maxn][26],f[maxn],val[maxn],C;

void add(string &s,int vl){
    int tmp=0;
    for(char ch:s){
	if(nxt[tmp][ch-'a']==0) nxt[tmp][ch-'a']=++C;
	tmp= nxt[tmp][ch-'a'];
    }
    val[tmp]+=vl;
}

void build(){
    queue<int>q;
    for(int i=0;i<26;i++){
	if(nxt[0][i]!=0) q.push(nxt[0][i]);
    }
    while(sz(q)){
	int u=q.front();
	val[u]+=val[f[u]];
	q.pop();
	for(int i=0;i<26;i++){
	    if(nxt[u][i]==0) nxt[u][i]=nxt[f[u]][i];
	    else f[nxt[u][i]]=nxt[f[u]][i],q.push(nxt[u][i]);
	}
    }
}

int dp[maxn],tmp[maxn];

void go(int ch){
    fill(tmp,tmp+maxn,-inf);
    for(int c=0;c<26;c++){
	if(ch!=-1 && ch!=c) continue;
	for(int i=0;i<=C;i++){
	    if(dp[i]!=-inf) tmp[nxt[i][c]]=max(tmp[nxt[i][c]], dp[i] + val[nxt[i][c]]);
	}
    }
    memcpy(dp,tmp,sizeof dp);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    fill(dp,dp+maxn,-inf);
    string a,b,c;cin>>a>>b>>c;
    add(b,1),add(c,-1),build();
    dp[0]=0;
    for(int i=0;i<sz(a);i++){
	if(a[i]=='*') go(-1);
	else go(a[i]-'a');	
    }
    int ans=-inf;
    for(int i=0;i<maxn;i++){
	ans=max(ans,dp[i]);
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.