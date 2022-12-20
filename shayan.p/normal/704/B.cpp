// Can U hack it?

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

const int maxn=5010;
const ll inf=1e18;

ll dp[maxn][maxn],x[maxn],cr[maxn],cl[maxn],gl[maxn],gr[maxn];
int n,s,e;

int main(){
    scanf("%d%d%d",&n,&s,&e);
    for(int i=1;i<=n;i++)
	scanf("%lld",&x[i]);
    for(int i=1;i<=n;i++)
	scanf("%lld",&cr[i]);
    for(int i=1;i<=n;i++)
	scanf("%lld",&cl[i]);
    for(int i=1;i<=n;i++)
	scanf("%lld",&gl[i]);
    for(int i=1;i<=n;i++)
	scanf("%lld",&gr[i]);
    if(s>e){
	for(int i=1;i<=n;i++){
	    swap(cr[i],gl[i]);
	    swap(cl[i],gr[i]);
	}
	swap(s,e);
    }
    for(int i=0;i<maxn;i++){
	for(int j=0;j<maxn;j++)
	    dp[i][j]=inf;
    }
    bool nmm=(1==s);
    dp[1][1]=cl[1]+gr[1]-x[1]-x[1];
    for(int i=2;i<=n;i++){
	nmm^=(i==e);
	for(int j=1;j<=i;j++){
	    ll A=inf,B=inf,C=inf,D=inf;
	    A=dp[i-1][j]+cr[i]+gr[i];
	    B=dp[i-1][j]+cl[i]+gl[i];
	    C=dp[i-1][j-1]+cl[i]+gr[i]-x[i]-x[i];
	    D=dp[i-1][j+1]+cr[i]+gl[i]+x[i]+x[i];
	    if(i==s) A=D=inf;
	    if(i==e) A=C=inf;
	    if(j==1 && nmm==1) B=inf;
	    dp[i][j]=min(A,min(B,min(C,D)));/*
	    cout<<i<<" "<<j<<" "<<dp[i][j]<<"   ";
	    if(dp[i][j]==A)cout<<"come right go right   0\n";
	    else if(dp[i][j]==B) cout<<"come left go left     0\n";
	    else if(dp[i][j]==C) cout<<"come left go right   -1\n";
	    else if(dp[i][j]==D) cout<<"come right go left   +1\n";*/
	}
	nmm^=(i==s);
    }
    dp[n][0]=dp[n-1][1]+cr[n]+gl[n]+x[n]+x[n];
    ll ans=dp[n][0]-cl[s]-gl[e]-x[e]+x[s];
    printf("%lld\n",ans);
}