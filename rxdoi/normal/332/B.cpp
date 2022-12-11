#include<cstdio>
using namespace std;

const int Maxn=2e5+19;
typedef long long LL;
int n,k,Dis,AA,AB;
LL Max,AM,A[Maxn],c[Maxn];

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&A[i]);
	for (int i=0;i<k;i++) c[0]+=A[i];
	for (int i=k;i<n;i++) c[i-k+1]=c[i-k]-A[i-k]+A[i];
	Max=c[0];Dis=0;
	for (int i=k;i<n;i++) 
	{
		if (c[i]+Max>AM||
			c[i]+Max==AM&&Dis<AA||
			c[i]+Max==AM&&Dis==AA&&i<AB) {AM=c[i]+Max;AA=Dis;AB=i;}
		if (c[i-k+1]>Max) Max=c[i-k+1],Dis=i-k+1;
	}
	printf("%d %d\n",AA+1,AB+1);
}