#include<cstdio>
using namespace std;

const int Maxn=2e5+19;
typedef long long LL;
int n,opt,x,a,sz,MAX=2e5+5;
LL A[Maxn],B[Maxn];

inline void Add_1(int i,int x) {while (i<=MAX) A[i]+=x,i+=(i&-i);}
inline void Add_2(int i,int x) {while (i<=MAX) B[i]+=x,i+=(i&-i);}
inline LL Query_1(int i)
{
	LL Ans=0;
	while (i) Ans+=A[i],i-=(i&-i);
	return Ans;
}
inline LL Query_2(int i)
{
	LL Ans=0;
	while (i) Ans+=B[i],i-=(i&-i);
	return Ans;
}

int main()
{
	scanf("%d",&n);
	sz=1;
	while (n--)
	{
		scanf("%d",&opt);
		if (opt==1)
		{
			scanf("%d%d",&a,&x);
			Add_1(1,x);		Add_2(1,x);
			Add_1(a+1,-x);	Add_2(a+1,(-x)*(a+1));
		}
		if (opt==2)
		{
			scanf("%d",&x);
			sz++;
			Add_1(sz,x);		Add_1(sz+1,-x);
			Add_2(sz,x*sz);	Add_2(sz+1,(-x)*(sz+1));
		}
		if (opt==3)
		{
			LL del=Query_1(sz);
			Add_1(sz,-del);	Add_2(sz,(-del)*sz);
			Add_1(sz+1,del);Add_2(sz+1,(del)*(sz+1));
			sz--;
		}
		printf("%.6lf\n",(double)(1LL*(sz+1)*Query_1(sz)-Query_2(sz))/(double)sz);
	}
}