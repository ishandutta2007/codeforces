#include<cstdio>
using namespace std;

const int Maxn=100+19;
int A[Maxn],n,Max=0;

int gcd(int a,int b) {return !b?a:gcd(b,a%b);}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) 
	{
		scanf("%d",&A[i]);
		if (A[i]>Max) Max=A[i];
	}
	for (int i=0;i<n;i++) Max=gcd(Max,A[i]);
	printf("%d\n",Max*n);
	return 0;
}