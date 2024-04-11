#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long x[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    ll g = 0;
    for (int i=1;i<=n;i++)
    {
        cin>>x[i];
        if (i==2)
            g = x[i]-x[i-1];
        else if (i>2)
            g = __gcd(g,x[i]-x[i-1]);
    }
    for (int i=1;i<=m;i++)
    {
        long long y;
        cin>>y;
        if (g%y==0)
        {
            cout<<"YES"<<endl;
            cout<<x[1]<<' '<<i<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}