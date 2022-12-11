#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=4000+19;
typedef long long LL;
char s[Maxn];
int C[Maxn],cnt[Maxn*10],tar;
LL Ans;

int main()
{
	scanf("%d",&tar);
	scanf("%s",s);
	for (int i=0;i<strlen(s);i++) C[i+1]=C[i]+s[i]-'0';
	for (int i=1;i<=strlen(s);i++)
		for (int j=1;j<=i;j++) cnt[C[i]-C[j-1]]++;
	if (tar==0)
	{
		for (int i=1;i<=C[strlen(s)];i++) Ans+=cnt[0]*cnt[i];
		Ans=2LL*Ans+1LL*cnt[0]*cnt[0];
	}
	else
		for (int i=1;i<=C[strlen(s)];i++)
			if (tar%i==0&&tar/i<=C[strlen(s)]) Ans+=1LL*cnt[i]*cnt[tar/i];
	printf("%I64d\n",Ans);
}