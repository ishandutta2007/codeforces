#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=1000+19;
char s[Maxn];
int cnt[27],x;

int main()
{
	scanf("%s",s);
	for (int i=0;i<strlen(s);i++) cnt[s[i]-'a']++;
	for (int i=0;i<26;i++) x+=(cnt[i]&1);
	if (x<=1) puts("First");
		else puts(x&1?"First":"Second");
}