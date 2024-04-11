#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char s[200010];
int len,ans1,ans2,cnt1[110],cnt2[110];

int main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;i++)
	{
		if(s[i]>='a'&&s[i]<='z')cnt1[s[i]-'a']++;
		else cnt2[s[i]-'A']++;
	}
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;i++)
	{
		if(s[i]>='a'&&s[i]<='z')cnt1[s[i]-'a']--,ans1+=(cnt1[s[i]-'a']>=0);
		else cnt2[s[i]-'A']--,ans1+=(cnt2[s[i]-'A']>=0);
	}
	for(int i=0;i<26;i++)
		if(cnt1[i]*cnt2[i]<0)ans2+=min(abs(cnt1[i]),abs(cnt2[i]));
	printf("%d %d",ans1,ans2);
}