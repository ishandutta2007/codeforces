#include<cstdio>
using namespace std;

const int Maxn=100+19;
int A[Maxn],n,Max,Gcd=0;

int gcd(int a,int b) {return !b?a:gcd(b,a%b);}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) 
	{
		scanf("%d",&A[i]);
		if (A[i]>Max) Max=A[i];
		Gcd=gcd(Gcd,A[i]);
	}
	printf("%s\n",(Max/Gcd-n)&1?"Alice":"Bob");
	return 0;
}