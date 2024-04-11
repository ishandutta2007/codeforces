#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
char str[MAXN];
bool used[26];
int cnt[26];
bool C(int k)
{
    memset(used,true,sizeof(used));
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<k;i++)
        cnt[str[i]-'a']++;
    for(int i=0;i<26;i++)
        if(cnt[i]==0) used[i]=false;
    for(int i=0;i<=n-k-1;i++)
    {
        cnt[str[i]-'a']--;
        cnt[str[i+k]-'a']++;
        if(cnt[str[i]-'a']==0) used[str[i]-'a']=false;
    }
    for(int i=0;i<26;i++)
        if(used[i]) return true;
    return false;
}
int main()
{
    scanf("%s",str);
    n=strlen(str);
    int left=0,right=n;
    while(right-left>1)
    {
        int mid=(left+right)/2;
        if(C(mid)) right=mid; else left=mid;
    }
    printf("%d\n",right);
    return 0;
}