#include<cstdio>
#include<cstring>
using namespace std;

char c[100+19];
int n,cnt['z'+19];

int main()
{
	scanf("%s",c);
	for (int i=0;i<strlen(c);i++) cnt[c[i]]++;
	for (int i='a';i<='z';i++) if (cnt[i]) n++;
	printf("%s\n",n&1?"IGNORE HIM!":"CHAT WITH HER!");
}