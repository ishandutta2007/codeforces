#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
map<int,int> mp;
int main()
{
    ios_base::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    mp[0]=1;
    long long tot=(1LL<<k)-1;
    long long x=0;
    long long ret=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        x^=a[i];
        if (mp[tot-x]<mp[x])
        {
            ret+=(i+1)-mp[tot-x];
            mp[tot-x]++;
        }
        else {
            ret+=(i+1)-mp[x];
            mp[x]++;
        }
    }
    cout<<ret<<endl;
}