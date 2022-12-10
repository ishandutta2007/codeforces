#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=500+19,P=1e9+7;
int f[2][N][N],n,m,T,c,tmp,Ans;
char s[N][N];

bool Check(int x1,int y1,int x2,int y2)
{
	return x1<=x2&&y1<=y2&&s[x1][y1]==s[x2][y2];
}

int main()
{
	n=IN(),m=IN();
	For(i,1,n+1) scanf("%s",s[i]+1);
	T=(n+m)/2;
	f[c^1][1][n]=(s[1][1]==s[n][m]);
	For(i,1,T)
	{
		c^=1;
		memset(f[c^1],0,sizeof(f[c^1]));
		For(x1,1,n+1) For(x2,x1,n+1)
		{
			int y1=i+1-x1,y2=m-(i+1-(n-x2+1))+1;
			if (tmp=f[c][x1][x2])
			{
				if (Check(x1+1,y1,x2-1,y2)) (f[c^1][x1+1][x2-1]+=tmp)%=P;
				if (Check(x1+1,y1,x2,y2-1)) (f[c^1][x1+1][x2]+=tmp)%=P;
				if (Check(x1,y1+1,x2-1,y2)) (f[c^1][x1][x2-1]+=tmp)%=P;
				if (Check(x1,y1+1,x2,y2-1)) (f[c^1][x1][x2]+=tmp)%=P;
			}
		}
	}
	For(i,1,n+1) For(j,1,n+1) (Ans+=f[c^1][i][j])%=P;
	printf("%d\n",Ans);
}