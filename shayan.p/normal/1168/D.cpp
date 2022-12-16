// High above the clouds there is a rainbow...

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

const int maxn=15e4+10,mod=1e9+7;
const ll inf=1e18;

vector<int>v[maxn],g[maxn];
int pr[maxn],who[maxn],bel[maxn];
int cnt[26][maxn],dp[26][maxn],sm[maxn];
int HH=-1,h[maxn],cbad=0;
bool all=0;

void dfs(int u,int H=0){
    h[u]=H;
    if(sz(v[u])==0){
	if(HH==-1) HH=H;
	all|= HH!=H;
    }
    for(int y:v[u]){
	dfs(y,H+1);
    }
    if(u!=1 && sz(v[u])!=1){
	int tmp=u;
	while(tmp!=1 && (tmp==u || sz(v[tmp])==1)){
	    bel[tmp]=u;
	    if(who[tmp]!=-1) cnt[who[tmp]][u]++;
	    tmp=pr[tmp];
	}
	pr[u]=tmp;
	g[pr[u]].PB(u);
    }
}
void dfs2(int u){
    for(int y:g[u]){
	dfs2(y);
	for(int i=0;i<26;i++){
	    dp[i][u]=max(dp[i][u],dp[i][y]+cnt[i][y]);
	}
    }
    sm[u]=HH-h[u];
    for(int i=0;i<26;i++){
	sm[u]-=dp[i][u];
    }
    cbad+=sm[u]<0;
}
void upd(int u,int c){
    while(u>0){
	cbad-=sm[u]<0, sm[u]+=dp[c][u];
	dp[c][u]=0;
	for(int y:g[u]){
	    dp[c][u]=max(dp[c][u],dp[c][y]+cnt[c][y]);
	}
	sm[u]-=dp[c][u], cbad+=sm[u]<0;
	u=pr[u];
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q;cin>>n>>q;
    for(int i=2;i<=n;i++){
	char ch;cin>>pr[i]>>ch;
	if(ch=='?') who[i]=-1;
	else who[i]=ch-'a';
	v[pr[i]].PB(i);
    }
    dfs(1);
    dfs2(1);
    
    while(q--){
	int u;cin>>u;
	char ch;cin>>ch;
	int c=-1;
	if(ch!='?') c=ch-'a';
	if(all){
	    cout<<"Fou\n";
	    continue;
	}
	if(who[u]!=-1)
	    cnt[who[u]][bel[u]]--, upd(bel[u],who[u]);
	who[u]=c;
	if(who[u]!=-1)
	    cnt[who[u]][bel[u]]++, upd(bel[u],who[u]);
	if(cbad>0){
	    cout<<"Fou\n";
	    continue;
	}
	ll ans=0;
	for(int i=0;i<26;i++)
	    ans+=1ll*(i+1)*(sm[1]+dp[i][1]);
	cout<<"Shi "<<ans<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.