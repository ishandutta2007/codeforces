#include<bits/stdc++.h>
#define MAXN 2005
using namespace std;
int n,k;
int a[MAXN],b[MAXN],s[MAXN];
set<int> save;
bool bs(int arr[],int x)
{
    int lb=-1,ub=k;
    while(ub-lb>1)
    {
        int mid=(lb+ub)/2;
        if(arr[mid]>=x)
        {
            ub=mid;
        }
        else
        {
            lb=mid;
        }
    }
    if(ub<k&&arr[ub]==x) return true; else return false;
}
void check(int x)
{
    int c[MAXN];
    c[0]=b[0]-s[x];
    for(int i=1;i<k;i++)
        c[i]=c[i-1]+a[i];
    sort(c,c+k);
    for(int i=0;i<n;i++)
    {
        if(!bs(c,b[i]))
        {
            return;
        }
    }
    save.insert(c[0]-a[0]);
}
int main()
{
    scanf("%d %d",&k,&n);
    for(int i=0;i<k;i++)
        scanf("%d",&a[i]);
    s[0]=0;
    for(int i=1;i<k;i++)
        s[i]=s[i-1]+a[i];
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    int cnt=0;
    for(int i=0;i<k;i++)
       check(i);
    printf("%d\n",save.size());
    return 0;
}