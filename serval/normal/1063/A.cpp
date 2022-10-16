#include <cstdio>
using namespace std;
int n,i,j;
int cnt[26];
char s[100005];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for (i=1;i<=n;i++)
		cnt[s[i]-'a']++;
	for (i=0;i<26;i++)
		for (j=1;j<=cnt[i];j++)
			printf("%c",i+'a');
	printf("\n");
	return 0;
}