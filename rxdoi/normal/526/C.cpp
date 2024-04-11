#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int S,C,Ha,Hb,Wa,Wb;
long long Ans;

int main()
{
	scanf("%d%d%d%d%d",&C,&Ha,&Hb,&Wa,&Wb);
	S=sqrt(C);
	if (Wa>Wb) swap(Ha,Hb),swap(Wa,Wb);
	if (Wb>S)
		for (int i=0;1LL*i*Wb<=C;i++) Ans=max(Ans,1LL*i*Hb+1LL*(C-i*Wb)/Wa*Ha);
	else
	{
		if (1LL*Ha*Wb>1LL*Hb*Wa) swap(Ha,Hb),swap(Wa,Wb);
		for (int i=0;i<Wb;i++) Ans=max(Ans,1LL*i*Ha+1LL*(C-i*Wa)/Wb*Hb);
	}
	printf("%I64d\n",Ans);
}