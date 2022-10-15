#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
#define MAXN 100
using namespace std;
char str[MAXN];
int main()
{
    scanf("%s",str);
    int cnt=0,ans=0;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='Y')
        {
            cnt++;
            ans=max(cnt,ans);
            cnt=0;
        }
        else cnt++;
    }
    ans=max(cnt+1,ans);
    printf("%d\n",ans);
    return 0;
}