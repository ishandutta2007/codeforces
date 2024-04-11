#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
int n,m,k;
bool fuck[55][55];
int qx[3005],qy[3005];int tot=0;
int main(){
	scanf("%d%d%d",&n,&m,&k);int ans=0;
	for(int i=2;i<=n+m;i++){
		if(!k)break;
		for(int j=1;j<=n;j++)
		if(i-j>0&&i-j<=m){
			if(!k)break;
			k--;
			fuck[j][i-j]=1;
			ans+=i-1;
			++tot;qx[tot]=j;qy[tot]=i-j;
		}
	}
	printf("%d\n",ans);
	for(int i=tot;i>=1;i--){
		for(int j=1;j<=qx[i];j++)printf("(%d,1) ",j);
		for(int j=2;j<=qy[i];j++)printf("(%d,%d) ",qx[i],j);
		printf("\n");
	}
	return 0;
}