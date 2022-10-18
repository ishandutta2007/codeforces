#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mod %MOD

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;

ld step(ld k, int m)
{
    if (m==1) return k;
    if (m%2==1) return step(k,m-1)*k;
    ld p=step(k,m/2);
    return p*p;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>m>>n;
    ld ans=0;
    for (int i=1; i<=m; i++)
        ans+=(step((ld)i/(ld)m,n)-step((ld)(i-1)/(ld)m,n))*(ld)i;
    cout.precision(10);
    cout<<fixed;
    cout<<ans<<endl;
}