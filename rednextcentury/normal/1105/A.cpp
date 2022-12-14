#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int ret=1e9;
    int best=-1;
    for (int t=1;t<=100;t++)
    {
        int cur=0;
        for (int i=1;i<=n;i++)
        {
            cur+=min(abs(t-a[i]),min(abs(t+1-a[i]),abs(t-1-a[i])));
        }
        if (ret>cur)ret=cur,best=t;
        ret=min(ret,cur);
    }
    cout<<best<<' '<<ret<<endl;
}