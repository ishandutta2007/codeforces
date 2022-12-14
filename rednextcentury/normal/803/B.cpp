#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int pre[1000001];
int suf[1000001];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    pre[0]=10000000,suf[n+1]=10000000;
    for (int i=1;i<=n;i++)
    {
        if (a[i]==0)
            pre[i]=0;
        else pre[i]=pre[i-1]+1;
    }
    for (int i=n;i>=1;i--)
    {
        if (a[i]==0)
            suf[i]=0;
        else suf[i]=suf[i+1]+1;
    }
    for (int i=1;i<=n;i++)
        cout<<min(suf[i],pre[i])<<' ';
    cout<<endl;
}