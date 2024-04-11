#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;

const int Maxn=5e5+19;
int F[Maxn][26],pre[Maxn][26],Len,k,Min=(1<<30)-1,Dis;
char s[Maxn],Ans[Maxn];

int main()
{
	scanf("%d%d",&Len,&k);
	scanf("%s",s);
	memset(F,60,sizeof(F));
	for (int i=0;i<Len;i++)
		for (int j=0;j<k;j++)
			if (!i) F[i][j]=(s[i]!=j+'A');
				else
					for (int L=0;L<26;L++)
						if (L!=j&&F[i-1][L]+(s[i]!=j+'A')<F[i][j])
							F[i][j]=F[i-1][L]+(s[i]!=j+'A'),pre[i][j]=L;
	for (int i=0;i<k;i++) 
		if (F[Len-1][i]<Min) Min=F[Len-1][i],Dis=i;
	printf("%d\n",Min);
	while (Len--)
	{
		Ans[Len]=Dis+'A';
		Dis=pre[Len][Dis];
	}
	printf("%s\n",Ans);
}