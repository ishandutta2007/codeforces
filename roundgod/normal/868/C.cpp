#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
bool ext[16];
int n,k;
int a[MAXN][4];
int main()
{
    scanf("%d %d",&n,&k);
    memset(ext,false,sizeof(ext));
    for(int i=0;i<n;i++)
    {
        int x=0;
        for(int j=0;j<k;j++)
        {
            scanf("%d",&a[i][j]);
            x=x*2+(1-a[i][j]);
        }
        int sub=x;
        do
        {
            ext[sub]=true;
            sub=(sub-1)&x;
        }
        while(sub!=x);
    }
    for(int i=0;i<n;i++)
    {
        int x=0;
        for(int j=0;j<k;j++)
            x=x*2+a[i][j];
        if(ext[x])
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}