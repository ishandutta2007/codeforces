#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
using namespace std;
int n,k;
int a[MAXN];
int res,ans;
int main()
{
    scanf("%d",&n);
    res=INF;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        res=min(res,a[i]);
    }
    int cnt=0,ans=INF;
    bool f=false;
    for(int i=0;i<n;i++)
    {
        if(f)
        {
            if(a[i]==res) {ans=min(ans,cnt); cnt=1;}
            else cnt++;
        }
        else if(a[i]==res) {f=true; cnt=1;}
    }
    printf("%d\n",ans);
    return 0;
}