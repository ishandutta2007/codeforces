#include<cstdio>
#include<algorithm>
#define mp make_pair
using namespace std;

const int Maxn=1e5+19;
pair<int,int> A[Maxn];
int Min[21][Maxn],Gcd[21][Maxn];
int n,Q,L,R,x;

inline int _min(int a,int b) {return a<b?a:b;}
inline int _gcd(int a,int b) {return !b?a:_gcd(b,a%b);}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x),Gcd[0][i]=Min[0][i]=x,A[i]=make_pair(x,i);
	sort(A+1,A+n+1);
	for (int i=1;i<=20;i++)
		for (int j=1;j+(1<<i)-1<=n;j++)
		{
			Gcd[i][j]=_gcd(Gcd[i-1][j],Gcd[i-1][j+(1<<i-1)]);
			Min[i][j]=_min(Min[i-1][j],Min[i-1][j+(1<<i-1)]);
		}
	scanf("%d",&Q);
	while (Q--)
	{
		scanf("%d%d",&L,&R);
		int k=0;
		for (;1<<(k+1)<=R-L+1;k++);
		int GCD=_gcd(Gcd[k][L],Gcd[k][R-(1<<k)+1]);
		int MIN=_min(Min[k][L],Min[k][R-(1<<k)+1]);
		int cnt=upper_bound(A+1,A+n+1,mp(GCD,R))-lower_bound(A+1,A+n+1,mp(GCD,L));
		printf("%d\n",R-L+1-(GCD==MIN?cnt:0));
	}
}