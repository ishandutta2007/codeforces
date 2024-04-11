#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int i,j,k,l,m,n,o,p,len1,len2,a[27],ans,b[27];
char s1[1002],s2[1002];

int main()
{
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	len1=strlen(s1+1);
	len2=strlen(s2+1);
	for(i=1;i<=len1;i++)
	a[s1[i]-'a'+1]++,b[s1[i]-'a'+1]=1;
	for(i=1;i<=len2;i++)
	{
		if(a[s2[i]-'a'+1]>0)a[s2[i]-'a'+1]--,ans++;
		if(b[s2[i]-'a'+1]==0){printf("-1");return 0;}
	}
	if(ans==0)ans=-1;
	printf("%d",ans);
}