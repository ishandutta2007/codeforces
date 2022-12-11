#include<cstdio>
#include<bitset>
using namespace std;

typedef long long LL;
bitset<300000000> F;
int L,R,Ans;

int main()
{
	scanf("%d%d",&L,&R);
	Ans=(L<=2&&2<=R);
	for (int i=3;i*i<=R;i+=2) 
		if (!F[i])
			for (LL j=1LL*i*i;j<=R;j+=2*i) F[j]=1;
	for (int i=5;i<=R;i+=4) if (i>=L&&!F[i]) Ans++;
	printf("%d\n",Ans);
}