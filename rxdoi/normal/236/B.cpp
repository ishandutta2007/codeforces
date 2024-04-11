#include<cstdio>
using namespace std;

const int Mod=1073741824;
int a,b,c,F[100*100*100+19],Ans;

inline int calc(int x)
{
	if (F[x]) return F[x];
	int cnt=0;
	for (int i=1;i*i<=x;i++) 
	{
		if (i*i==x) cnt+=1;else
		if (x%i==0) cnt+=2;
	}
	return F[x]=cnt%Mod;
}

int main()
{
	scanf("%d%d%d",&a,&b,&c);
	for (int i=1;i<=a;i++)
		for (int j=1;j<=b;j++)
			for (int k=1;k<=c;k++) Ans=(Ans+calc(i*j*k))%Mod;
	printf("%d\n",Ans);
}