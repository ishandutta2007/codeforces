#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=100+19,oo=(1<<30)-1;
int K[Maxn],M,n,tmp,Ans=oo;

inline int min(int a,int b) {return a<b?a:b;}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&K[i]);
	for (int i=0;i<n;i++)
	{
		tmp=0;
		for (int j=0;j<K[i];j++) 
		{
			scanf("%d",&M);
			tmp+=M*5;
		}		
		Ans=min(Ans,tmp+K[i]*15);
	}
	printf("%d\n",Ans);
	return 0;
}