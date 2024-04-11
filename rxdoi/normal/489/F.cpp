#include<cstdio>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=500+19;
int A[N],S[3],f[2][N][N],c,s=1,n,m,P,t;
char ch[N];

int C(int x) {return (x-1)*x/2%P;}

int main()
{
	scanf("%d%d%d",&n,&m,&P);
	For(i,1,m+1)
	{
		scanf("%s",ch);
		For(j,0,n) A[j]+=(ch[j]-'0');
	}
	For(i,0,n) S[A[i]]++;
	f[c][S[0]][S[1]]=1;
	For(i,m+1,n+1)
	{
		for (int j=0;j<=n;j++)
			for (int k=0;j+k<=n;k++)
				if ((t=f[c][j][k]))
				{
					if (j>=2) (f[s][j-2][k+2]+=1LL*t*C(j)%P)%=P;
					if (k>=2) (f[s][j][k-2]+=1LL*t*C(k)%P)%=P;
					if (j>=1) (f[s][j-1][k]+=1LL*t*j*k%P)%=P;
				}
		c^=1,s^=1;
		memset(f[s],0,sizeof(f[s]));
	}
	printf("%d\n",f[c][0][0]);
}