#include<cstdio>
#include<cctype>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=50+19;
int n,m,Ans,cnt[128];
char s[N][N];

int main()
{
	scanf("%d%d",&n,&m);
	For(i,1,n+1) scanf("%s",s[i]+1);
	For(i,1,n) For(j,1,m)
	{
		cnt['a']=cnt['f']=cnt['c']=cnt['e']=0;
		For(k,0,2) For(l,0,2) cnt[s[i+k][j+l]]++;
		if (cnt['a']==1&&cnt['f']==1&&cnt['c']==1&&cnt['e']==1) Ans++;
	}
	printf("%d\n",Ans);
}