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

const int Top=5000000,N=Top+19;
int vis[N],Minp[N],p[N];
int cnt,T,a,b;
long long num[N];

int main()
{
	for (int i=2;i<=Top;i++)
	{
		if (!vis[i]) {p[cnt++]=i,Minp[i]=i;}
		for (int j=0;p[j]*i<=Top;j++)
		{
			vis[p[j]*i]=1,Minp[p[j]*i]=p[j];
			if (i%p[j]==0) break;
		}
	}
	For(i,2,Top+1) num[i]=num[i/Minp[i]]+1;
	For(i,2,Top+1) num[i]+=num[i-1];
	for (T=IN();T--;) b=IN(),a=IN(),printf("%I64d\n",num[b]-num[a]);
}