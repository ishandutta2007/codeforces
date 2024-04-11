#include<cstdio>
using namespace std;

const int Maxn=100+19;
int F[Maxn][Maxn],n,m;

inline int calc(int x,int y)
{
	if (x*y==0) return 0;
	return 1-calc(x-1,y-1);
}

int main()
{
	scanf("%d%d",&n,&m);
	printf("%s\n",calc(n,m)?"Akshat":"Malvika");
}