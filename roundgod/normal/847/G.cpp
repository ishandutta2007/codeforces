#include<cmath>
#include<set>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int cnt[10];
char s[10];

int main()
{
    int n,ans;
    scanf("%d",&n);
    memset(cnt,0,sizeof(cnt));
    for (int i=0;i<n;i++){
        scanf("%s",s);
        for (int j=0;j<7;j++)
            if (s[j]=='1') cnt[j]++;
    }
    ans=0;
    for (int i=0;i<7;i++) ans=max(ans,cnt[i]);
    printf("%d\n",ans);
}