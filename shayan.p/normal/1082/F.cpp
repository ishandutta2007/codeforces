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

const int maxn=510,maxk=12;

int nxt[maxn][26],cnt[maxn],C;
int dp[maxn][maxn][maxk],dph[maxn][maxn][maxk],tmp[maxk],tmph[maxk];

void Add(string &s,int x){
    int tmp=0;
    for(char ch:s){
	int num=ch-'0';
	cnt[tmp]+=x;
	if(nxt[tmp][num]==0)
	    nxt[tmp][num]=++C;
	tmp=nxt[tmp][num];
    }
    cnt[tmp]+=x;
}

void dfs(int u){
    for(int i=0;i<26;i++){
	if(nxt[u][i]!=0)
	    dfs(nxt[u][i]);
    }
    for(int h=0;h<maxn;h++)
	dph[u][h][0]=cnt[u]*h;
    for(int h=0;h<maxn-1;h++){
	for(int i=0;i<26;i++){
	    int y=nxt[u][i];
	    if(y==0) continue;
	    memset(tmp,0,sizeof tmp);
	    memset(tmph,0,sizeof tmph);
	    for(int cnt0=0;cnt0<maxk;cnt0++){
		for(int cnt1=0;cnt1+cnt0<maxk;cnt1++){
		    tmp[cnt0+cnt1]=max(tmp[cnt0+cnt1],dp[u][h][cnt0]+dp[y][h+1][cnt1]);
		    tmph[cnt0+cnt1]=max(tmph[cnt0+cnt1],dph[u][h][cnt0]+dp[y][1][cnt1]);
		}
	    }
	    for(int c=0;c<maxk;c++)
		dp[u][h][c]=tmp[c],dph[u][h][c]=tmph[c];
	}
	for(int c=1;c<maxk;c++)
	    dp[u][h][c]=max(dp[u][h][c],dph[u][h][c-1]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,sm=0;cin>>n>>k;
    while(n--){
	string s;int x;cin>>s>>x;
	Add(s,x);
	sm+=sz(s)*x;
    }
    dfs(0);
    int ans=0;
    for(int i=0;i<=k;i++)
	ans=max(ans,dp[0][0][i]);
    return cout<<sm-ans<<endl,0;
}