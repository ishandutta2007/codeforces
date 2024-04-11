#include<cstdio>

#define mo 1000000009
#define N 4010

using namespace std;

int n,w,b,ans;
int C[N][N];

int main()
{
	scanf("%d%d%d",&n,&w,&b);
	for(int i=0;i<=w||i<=b;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			if(C[i][j]>=mo)C[i][j]-=mo;
		}
	}
	for(int i=1;i<=n-2&&i<w;i++)
		for(int j=i+1;j<=n-1&&j-i<=b;j++)
		{
			ans+=1ll*C[w-1][i+n-j-1]*C[b-1][j-i-1]%mo;
			if(ans>=mo)ans-=mo;
		}
	for(int i=1;i<=w;i++)
		ans=1ll*ans*i%mo;
	for(int i=1;i<=b;i++)
		ans=1ll*ans*i%mo;
	printf("%d\n",ans);
}