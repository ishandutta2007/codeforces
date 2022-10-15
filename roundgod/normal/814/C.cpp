#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 1500
using namespace std;
int n,q;
int d[MAXN][MAXN],ans[MAXN][26];
char str[MAXN];
int num[MAXN];
int main()
{
    scanf("%d\n",&n);
    scanf("%s",str);
    for(int i=0;i<n;i++)
        num[i]=(int)(str[i]-97);
    for(int i=0;i<n;i++)
        for(int j=0;j<26;j++)
          ans[i][j]=i;
    for(int k=0;k<26;k++)
    {
        for(int i=0;i<n-1;i++)
        {
            if(num[i]==k) d[i][i]=0; else d[i][i]=1;
            for(int j=i+1;j<n;j++)
            {
                if(num[j]==k) d[i][j]=d[i][j-1]; else d[i][j]=d[i][j-1]+1;
                ans[d[i][j]][k]=max(ans[d[i][j]][k],j-i+1);
            }
        }
    }
    for(int i=0;i<26;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ans[j][i]=max(ans[j][i],ans[j-1][i]+1);
            if(ans[j][i]>n) ans[j][i]=n;
        }
    }
    scanf("%d",&q);
    int x;
    char y;
    for(int i=0;i<q;i++)
    {
        scanf("%d",&x);
        getchar();
        y=getchar();
        int p=y-97;
        printf("%d\n",ans[x][p]);
    }
    return 0;
}