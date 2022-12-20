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

const int maxn=3010,Max=maxn*maxn,mod=1e9+7;
const ll inf=1e18;

int dp[Max];
int nxt[2][Max];
pii par[Max];
bool a[maxn];

int Add(int a,int b,int c){
    par[a]={b,c};
    nxt[c][b]=a;
    int msk=0,tmp=a;
    for(int i=0;i<3;i++){
	if(par[tmp].S) msk+=(1<<(3-i));
	dp[a]=(dp[a]+dp[tmp=par[tmp].F])%mod;
	if(tmp==0) return dp[a];
    }
    msk+=par[tmp].S;
    tmp=par[tmp].F;
    if(msk!=3 && msk!=5 && msk!=14 && msk!=15) dp[a]=(dp[a]+dp[tmp])%mod;
    return dp[a];
}

void dfs(int u=0,string str=""){
    cout<<u<<" "<<str<<" "<<dp[u]<<endl;
    for(int i=0;i<2;i++)
	if(nxt[i][u]!=0)
	    dfs(nxt[i][u],str+char(i+'0'));
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    dp[0]=1;
    int ans=0,C=0;
    for(int i=0;i<n;i++){
	cin>>a[i];
	int tmp=0;
	for(int j=i;j>=0;j--){
	    if(nxt[a[j]][tmp]==0)
		ans=(ans+Add(++C,tmp,a[j]))%mod;
	    tmp=nxt[a[j]][tmp];
	}
	//	dfs();
	cout<<ans<<"\n";
    }
}