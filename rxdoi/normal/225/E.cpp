#include<cstdio>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int P=1e9+7;
int Exp[]=
{
	0,
	2,3,5,7,13,
	17,19,31,61,89,
	107,127,521,607,1279,
	2203,2281,3217,4253,4423,
	9689,9941,11213,19937,21701,
	23209,44497,86243,110503,132049,
	216091,756839,859433,1257787,1398269,
	2976221,3021377,6972593,13466917,20996011
},n;

int Pow(int a,int b)
{
	int res=1;
	for (;b;b>>=1,a=1LL*a*a%P) if (b&1) res=1LL*res*a%P;
	return res;
}

int main()
{
	scanf("%d",&n);
	printf("%d\n",(Pow(2,Exp[n]-1)-1+P)%P);
}