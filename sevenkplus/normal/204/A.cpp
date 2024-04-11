#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll p[20];
ll ff(ll x)
{
	if(x<=9)return x;
	ll S=9;
	for(int i=1;i<18;i++)
		for(int j=1;j<=9;j++)
			if(x/p[i]>j)S+=p[i-1];else
			if(x/p[i]==j)
			{
				S+=x%p[i]/10;
				if(x%10>=j)S++;
			}
	return S;
}
int main()
{
	p[0]=1;
	for(int i=1;i<20;i++)p[i]=p[i-1]*10;
	ll L,R;
	scanf("%I64d%I64d",&L,&R);
	printf("%I64d\n",ff(R)-ff(L-1));
	return 0;
}