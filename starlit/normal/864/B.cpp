#include<iostream>
#include<cstdio>
#include<cstring>
#define N 205
using namespace std;
int n,tms,ans,a[26];
char s[N];
int main()
{
	scanf("%d%s",&n,s);
	for(int i=0;i<=n;i++)
    if(s[i]>='a'&&s[i]<='z')
    {
        if(!(a[s[i]-'a']++))
        tms++;
    }
    else
    {
        if(tms>ans)ans=tms;
        tms=0;memset(a,0,sizeof a);
    }
    printf("%d",ans);
}