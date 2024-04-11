#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

char s1[10086],s2[10086];
int len1,len2,ans[10086];

int main()
{
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	len1=strlen(s1+1);
	len2=strlen(s2+1);
	for(int i=1;i<=len1;i++)
		ans[i]=s1[i]-'a';
	ans[len1]++;
	for(int i=len1;i;i--)if(ans[i]>=26)ans[i-1]++,ans[i]-=26;
	ans[0]++;
	for(int i=1;i<=len1;i++)
	{
		if(ans[i]+'a'>s2[i])return puts("No such string"),0;
		if(ans[i]+'a'<s2[i]){ans[0]--;break;}
	}
	if(ans[0])return puts("No such string"),0;
	for(int i=1;i<=len1;i++)putchar(ans[i]+'a');
}