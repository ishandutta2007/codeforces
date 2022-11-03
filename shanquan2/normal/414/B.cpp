#include<cstdio>
#define M 1000000007
using namespace std;

int p[1000],top=0;
bool vis[2001]={0};
int c[2010][2010],cnt[2010];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(k==1){
		printf("%d\n",n);
		return 0;
	}
	for(int i=2;i<=2000;i++){
		if(vis[i])continue;
		p[top++]=i;
		for(int j=2;i*j<=2000;j++)vis[i*j]=1;
	}
//	for(int i=0;i<top;i++)printf("%d ",p[i]);
	for(int i=0;i<2010;i++){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%M;
	}
	for(int i=1;i<=n;i++){
		long long q=1;
		int x=i;
		for(int j=0;j<top;j++){
			int t=0;
			while(x%p[j]==0){
				t++;
				x/=p[j];
			}
			q*=c[t+k-2][k-2];q%=M;
		}
		cnt[i]=q;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;i*j<=n;j++)
			ans+=cnt[j],ans%=M;
	printf("%d\n",ans);
	return 0;
}