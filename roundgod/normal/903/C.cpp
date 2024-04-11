#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int a[MAXN];
int main()
{
    scanf("%d",&n);
    int ans=1;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int cnt=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1]) cnt++;
        else
        {
            ans=max(ans,cnt);
            cnt=1;
        }
    }
    ans=max(ans,cnt);
    printf("%d\n",ans);
    return 0;
}