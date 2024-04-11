#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=1e5+19;
typedef long long LL;
char s[Maxn];
LL F[2],cnt[2][Maxn];

int main()
{
	scanf("%s",s);
	int Len=strlen(s);
	for (int i=0;i<Len;i++)
	{
		cnt[i%2][s[i]-'a']++;
		F[0]+=cnt[i%2][s[i]-'a'];
		F[1]+=cnt[1-i%2][s[i]-'a'];
	}
	printf("%I64d %I64d\n",F[1],F[0]);
}