// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define qqq(a) cerr<<"error "<<a<<endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e6+10,mod=1e9+7;
const ll inf=1e18;

int a[maxn],f[maxn],cnt[maxn],dp[maxn];
bool is[maxn];
ll sm[maxn];

vector<int>v[maxn];

void dfs(int u){
    sm[u]=a[u];
    for(int y:v[u]){
	dfs(y);
	sm[u]+=sm[y];
    }
}

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}

void mdd(int &a,int &b){
    a+=b;
    if(a>mod)
	a-=mod;
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
    }
    for(int i=2;i<=n;i++){
	int u;scanf("%d",&u);
	v[u].PB(i);
    }
    dfs(1);

    int ans=0;

    for(int i=1;i<=n;i++){
	ll X=sm[1]/gcd(sm[1],sm[i]);
	if(X<=n)
	    f[X]++;
    }

    for(int i=1;i<=n;i++){
	for(int j=i;j<=n;j+=i){
	    if(sm[1]%j==0)
		cnt[j]+=f[i];
	}
    }

    for(int i=1;i<=n;i++){
	is[i]=(cnt[i]==i);
    }
    
    dp[1]=1;
    for(int i=1;i<=n;i++){
	for(int j=2*i;j<=n;j+=i){
	    if(is[j])
		mdd(dp[j],dp[i]);
	}
	mdd(ans,dp[i]);
    }

    printf("%d\n",ans);
}