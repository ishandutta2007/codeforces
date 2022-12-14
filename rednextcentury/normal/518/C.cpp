# include <iostream>
# include<algorithm>
#include <stdio.h>
using namespace std;
int before[1000000];
int after[1000000];
int num[1000000];
int a[1000000];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    a[n+1]=-1;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (i==0)
            before[a[i]]=-1;
        else
            before[a[i]]=a[i-1];
        num[a[i]]=i;
    }
    for (int i=1;i<=n;i++)

        after[a[i]]=a[i+1];
    long long ans=0;
    for (int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        ans+=(num[x]-1)/k+1;
        if (num[x]==1)
            continue;
        int j=num[x];
        swap(a[j],a[j-1]);
        num[x]--;
        num[before[x]]++;
        if (j>=2) after[a[j-2]]=a[j-1];
        if (j>=2) before[a[j-1]]=a[j-2];
        after[a[j-1]]=a[j];
        after[a[j]]=a[j+1];
        before[a[j+1]]=a[j];
        before[a[j]]=a[j-1];
    }
    cout<<ans<<endl;
}