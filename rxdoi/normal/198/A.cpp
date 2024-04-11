#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int k,b,n,t,Ans;
long long tmp;

int main()
{
	scanf("%d%d%d%d",&k,&b,&n,&t);
	for (Ans=0;;Ans++)
	{
		tmp+=pow(k,Ans);
		if (tmp>t) {printf("%d\n",max(n-(Ans-1),0));return 0;}
		tmp+=(b-1)*pow(k,Ans);
	}
}