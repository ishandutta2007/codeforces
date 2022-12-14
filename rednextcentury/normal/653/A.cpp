#include <bits/stdc++.h>
using namespace std;
int v[10000];
int a[10000];
int main()
{
    int n,m=0;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if (++v[x]==1)
            a[m++]=x;
    }
    sort(a,a+m);
    for (int i=2;i<m;i++)
    {
        if (a[i]-a[i-2]<=2)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}