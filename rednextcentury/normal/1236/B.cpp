#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long mod = 1000000007;
long long P(long long a,long long b)
{
    if (b==0)return 1;
    ll x = P(a,b/2);
    x = (x*x)%mod;
    if (b%2)x=(x*a)%mod;
    return x;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    long long ret = P(2,m) - 1 + mod;
    ret%=mod;
    ret = P(ret,n);
    ret%=mod;
    cout<<ret<<endl;

}