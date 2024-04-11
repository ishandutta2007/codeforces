#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int ret=0;
    for (int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        int sum=0;
        for (int j=l;j<=r;j++)
            sum+=a[j];
        if (sum>0)
            ret+=sum;
    }
    cout<<ret<<endl;
}