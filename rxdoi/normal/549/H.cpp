#include<cstdio>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Mid ((L+R)/2.0)
using namespace std;

typedef double Db;
Db a,b,c,d,L,R;

Db Min(Db a,Db b,Db x)
{
	return min(min((a-x)*(b-x),(a-x)*(b+x)),min((a+x)*(b-x),(a+x)*(b+x)));
}
Db Max(Db a,Db b,Db x)
{
	return max(max((a-x)*(b-x),(a-x)*(b+x)),max((a+x)*(b-x),(a+x)*(b+x)));
}
bool Check(Db x)
{
	Db L1=Min(a,d,x),R1=Max(a,d,x);
	Db L2=Min(b,c,x),R2=Max(b,c,x);
	if (L2>R1||L1>R2) return 0;else return 1;
}

int main()
{
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	L=0,R=1e10;
	For(i,0,500)
		if (Check(Mid)) R=Mid;else L=Mid;
	printf("%.10lf\n",L);
}