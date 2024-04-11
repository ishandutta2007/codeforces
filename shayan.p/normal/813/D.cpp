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

const int maxn=5010,MAX=1e5+10;

int dp[maxn][maxn],a[maxn];
vector<int> vec1[MAX],vec2[7],nxt[maxn];

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
	scanf("%d",&a[i]);
    }
    for(int i=n-1;i>=0;i--){
	vector<int> &v1=vec1[a[i]+1],&v2=vec2[a[i]%7],&v3=vec1[a[i]-1];
	for(int j=0;j<min(3,sz(v1));j++)
	    nxt[i].PB(v1[sz(v1)-j-1]);
	for(int j=0;j<min(3,sz(v2));j++)
	    nxt[i].PB(v2[sz(v2)-j-1]);
	for(int j=0;j<min(3,sz(v3));j++)
	    nxt[i].PB(v3[sz(v3)-j-1]);
	vec1[a[i]].PB(i);
	vec2[a[i]%7].PB(i);
	nxt[i].PB(n);
    }
    for(int i=n-1;i>=0;i--){
	for(int k:nxt[i])
	    dp[i][n]=max(dp[i][n],1+dp[k][n]);
    }
    int ans=0;
    for(int i=n-1;i>=0;i--){
	for(int j=i+1;j<n;j++){
	    for(int k:nxt[i]){
		int num=0;
		if(k<j) num=1+dp[k][j];
		if(j<k) num=1+dp[j][k];
		dp[i][j]=max(dp[i][j],num);
	    }
	    ans=max(ans,dp[i][j]);
	}
    }
    printf("%d\n",ans);
}