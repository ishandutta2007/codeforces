#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=1000+19;
int cnt['z'+19],k;
char s[Maxn];

int main()
{
	scanf("%d",&k);
	scanf("%s",s);
	for (int i=0;i<strlen(s);i++) cnt[s[i]]++;
	for (int i='a';i<='z';i++)
		if (cnt[i]%k!=0) {puts("-1\n");return 0;}
	for (int i=1;i<=k;i++)
		for (int j='a';j<='z';j++)
			for (int tmp=0;tmp<cnt[j]/k;tmp++) putchar(j);
	puts("");
}