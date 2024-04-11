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

const int maxn=3e5+10,mod=998244353;
const ll inf=1e18;

vector<int>v[maxn];
int mark[maxn],cnt1,cnt2,Pw[maxn];
bool IS;

void dfs(int u,int mrk=1){
    mark[u]=mrk;
    if(mrk==1) cnt1++;
    else cnt2++;
    for(int y:v[u]){
	if(mark[y]==0){
	    dfs(y,3-mrk);
	}
	else if(mark[y]==mark[u]){
	    IS=1;
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    Pw[0]=1;
    for(int i=1;i<maxn;i++){
	Pw[i]=2ll*Pw[i-1] %mod;
    }
    int q;cin>>q;
    while(q--){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
	    v[i].clear(),mark[i]=0;
	while(m--){
	    int a,b;cin>>a>>b;
	    v[a].PB(b);
	    v[b].PB(a);
	}
	int ans=1;
	for(int i=1;i<=n;i++){
	    if(mark[i]==0){
		cnt1=cnt2=0;
		IS=0;
		dfs(i);
		if(IS) ans=0;
		ans=1ll*ans*(Pw[cnt1]+Pw[cnt2])%mod;
	    }
	}
	cout<<ans<<"\n";
    }
    return 0;
}