#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n,k,a[MAXN];
bool used[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    memset(used,false,sizeof(used));
    int cnt=0;
    for(int i=0;i<n;i++)
        if(a[i]>0&&!used[a[i]-1]) used[a[i]-1]=true; else cnt++;
    printf("%d\n",cnt);
    return 0;
}