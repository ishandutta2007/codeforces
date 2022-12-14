#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    a[0]=9;
    a[n+1]=10;
    int ret=0;
    for (int i=0;i<=n;i++)
    {
        int zero=0;
        int ones=0;
        for (int j=i;j>=1;j--)
            if (a[j]==0)zero++;
        for (int j=i+1;j<=n;j++)
            if (a[j]==1)ones++;
        ret=max(ret,ones+zero);
    }
    cout<<ret<<endl;
}