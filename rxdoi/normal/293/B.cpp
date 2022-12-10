#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1000+19,P=1e9+7;
int A[N][N],s[N][N],f[N],c[N],b[N];
int n,m,k,cnt,Ans;

void DFS(int x,int y,int col)
{
	if (col>k) return;
	if (y==m+1) {DFS(x+1,1,col);return;}
	if (x==n+1)
	{
		int tmp=1;
		for (int i=k-col+1;i<=k-cnt;i++) tmp=1LL*tmp*i%P;
		(Ans+=tmp)%=P;return;
	}
	int &S=s[x][y];S=s[x][y-1]|s[x-1][y];
	if (A[x][y])
	{
		int t=A[x][y];
		if (c[t])
		{
			if (!(S>>c[t]&1)) S|=1<<c[t],DFS(x,y+1,col),S^=1<<c[t];
		} else
			For(i,1,col+2)
				if (!(S>>i&1)&&!b[i])
					S|=1<<i,b[i]=1,c[t]=i,DFS(x,y+1,max(i,col)),
					S^=1<<i,b[i]=0,c[t]=0;
	} else For(i,1,col+2) if (!(S>>i&1)) S|=1<<i,DFS(x,y+1,max(i,col)),S^=1<<i;
}

int main()
{
	n=IN(),m=IN(),k=IN();
	if (n+m-1>k) return puts("0"),0;
	For(i,1,n+1) For(j,1,m+1) f[A[i][j]=IN()]=1;
	For(i,1,k+1) cnt+=f[i];
	DFS(1,1,0);
	printf("%d\n",Ans);
}