#include<cstdio>
#include<map>
using namespace std;

typedef long long LL;
const int Maxn=1e5+19;
int A[Maxn],F[21][Maxn];
int n,Q,x;
map<int,LL> Ans;

inline int Gcd(int a,int b) {return !b?a:Gcd(b,a%b);}
inline int Get_F(int L,int R)
{
	int k=R-L+1,x=0;
	for (;1LL<<(x+1)<=k;x++);
	return Gcd(F[x][L],F[x][R-(1<<x)+1]);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]),F[0][i]=A[i];
	for (int i=1;i<=20;i++)
		for (int j=1;j<=n;j++) F[i][j]=1;
	for (int j=1;j<=20;j++)
		for (int i=1;i+(1<<j)-1<=n;i++) 
			F[j][i]=Gcd(F[j-1][i],F[j-1][i+(1<<(j-1))]);
	for (int i=1;i<=n;i++)
	{
		int j=i;
		while (j<=n)
		{
			int x=Get_F(i,j);
			int L=j,R=n,tmp=0;
			while (L<R)
			{
				int Mid=(L+R)>>1;
				if (Get_F(i,Mid)==x) tmp=Mid,L=Mid+1;else R=Mid;
			}
			if (Get_F(i,L)==x) tmp=L;
			Ans[x]+=tmp-j+1;
			j=tmp+1;
		}
	}
	scanf("%d",&Q);
	while (Q--)
	{
		scanf("%d",&x);
		printf("%I64d\n",Ans[x]);
	}
}