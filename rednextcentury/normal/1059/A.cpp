#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
int t[1000000];
int l[1000000];
int main()
{
    int n,L,p;
    cin>>n>>L>>p;
    int ret=0;
    for (int i=0;i<n;i++)
    {
        cin>>t[i]>>l[i];
        if (i==0 && t[i]>0)
        {
            ret+=(t[i])/p;
        }
        if (i>0)
        {
            ret+=(t[i]-t[i-1]-l[i-1])/p;
        }
        if (i+1==n)
        {
            ret+=(L-t[i]-l[i])/p;
        }
    }
    if (n==0)
    {
        ret=L/p;
    }
    cout<<ret<<endl;
}