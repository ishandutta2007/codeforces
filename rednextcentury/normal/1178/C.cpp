#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int P = (n+m);
    long long ret=1;
    long long mod = 998244353;
    while(P--)
    {
        ret=(ret*2)%mod;
    }
    cout<<ret<<endl;
}