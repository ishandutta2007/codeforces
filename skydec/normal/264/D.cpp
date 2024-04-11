#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 1010000
int la,lb;LL ans=0;
int l,r;
char str[MAXN];
int a[MAXN],b[MAXN];
int sum[MAXN][3][3];
int main(){
	scanf("%s",str+1);la=strlen(str+1);l=r=1;
	rep(i,1,la)if(str[i]=='R')a[i]=1;else if(str[i]=='B')a[i]=2;
	scanf("%s",str+1);lb=strlen(str+1);
	rep(i,1,lb)if(str[i]=='R')b[i]=1;else if(str[i]=='B')b[i]=2;
	rep(i,2,lb){
		rep(j,0,2)
		rep(k,0,2)
		sum[i][j][k]=sum[i-1][j][k];
		sum[i][b[i-1]][b[i]]++;
	}
	rep(i,1,la){
		while(r<lb&&b[r]!=a[i])r++;
		ans+=1ll*(r-l+1);
		if(i>1&&l<=lb&&(a[i]^a[i-1]))ans-=1ll*(sum[r][a[i]][a[i-1]]-sum[l][a[i]][a[i-1]]);
		if(l<=lb&&a[i]==b[l])l++;
		if(r<lb&&b[r]==a[i])r++;
	}
	printf("%I64d\n",ans);
	return 0;
}