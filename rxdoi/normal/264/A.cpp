#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=1e6+19;
char s[Maxn];
int L,R,Ans[Maxn*2];

int main()
{
	scanf("%s",s);
	int n=strlen(s);
	Ans[L=R=Maxn]=n;
	for (int i=n-2;i>=0;i--)
	{
		if (s[i]=='l') Ans[++R]=i+1;else Ans[--L]=i+1;
	}
	for (int i=L;i<=R;i++) printf("%d\n",Ans[i]);
}