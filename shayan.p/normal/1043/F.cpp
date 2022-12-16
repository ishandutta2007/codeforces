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

const int maxn=3e5+10,MASK=500;

int dp[maxn],cnt[maxn];
vector<int>prm[maxn];
int zr[MASK],arr[MASK];

int main(){
    int n;scanf("%d",&n);
    fill(dp,dp+maxn,n+1);
    for(int i=0;i<n;i++){
	int x;scanf("%d",&x);
	dp[x]=1;
    }
    for(int i=1;i<maxn;i++)
	for(int j=i;j<maxn;j+=i)
	    cnt[i]+=(dp[j]==1);
    for(int i=2;i<maxn;i++)
	if(prm[i].empty())
	    for(int j=i;j<maxn;j+=i)
      		prm[j].PB(i);
    for(int i=maxn-1;i>1;i--){
	if(dp[i]==n+1)continue;
	int N=sz(prm[i]);
	for(int msk=0;msk<(1<<N);msk++){
	    zr[msk]=1;
	    for(int j=0;j<N;j++)
		if(bit(msk,j))
		    zr[msk]*=prm[i][j];
	    arr[msk]=(__builtin_popcount(msk)&1?-1:1)*cnt[zr[msk]];
	}
	for(int j=0;j<N;j++)
	    for(int msk=(1<<N)-1;msk>=0;msk--)
		if(bit(msk,j))
		    arr[msk]+=arr[msk^(1<<j)];
	for(int msk=0;msk<(1<<N);msk++){
	    int &A=dp[i/zr[msk]];
	    if(arr[msk]>0)
		A=min(A,dp[i]+1);
	}
    }
    if(dp[1]==n+1) dp[1]=-1;
    printf("%d\n",dp[1]);
    return 0;
}