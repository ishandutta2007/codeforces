#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=1e5+19;
int n,mch[Maxn],is_p[Maxn],Ans,tmp[Maxn],with[Maxn][2];

int main()
{
	scanf("%d",&n);
	memset(is_p,1,sizeof(is_p));
	for (int i=3;i*2<=n;i++)
		if (is_p[i])
		{
			int cnt=0;
			for (int j=1;i*j<=n;j++) 
			{
				is_p[i*j]=0;
				if (!mch[i*j]) tmp[cnt++]=i*j;
			}
			if (cnt&1)
			{
				for (int j=3;j<cnt;j+=2) 
				{
					mch[tmp[j]]=mch[tmp[j+1]]=1;
					with[Ans][0]=tmp[j];
					with[Ans++][1]=tmp[j+1];
				}
				mch[tmp[0]]=mch[tmp[2]]=1;
				with[Ans][0]=tmp[0];
				with[Ans++][1]=tmp[2];
			} else	for (int j=0;j<cnt;j+=2) 
					{
						mch[tmp[j]]=mch[tmp[j+1]]=1;
						with[Ans][0]=tmp[j];
						with[Ans++][1]=tmp[j+1];
					}
		}
	int cnt=0;
	for (int i=2;i<=n;i+=2) if (!mch[i]) tmp[cnt++]=i;
	printf("%d\n",Ans+cnt/2);
	for (int i=0;i<Ans;i++) printf("%d %d\n",with[i][0],with[i][1]);
	for (int i=0;i+1<cnt;i+=2) printf("%d %d\n",tmp[i],tmp[i+1]);
}