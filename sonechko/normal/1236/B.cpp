#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int step(int x, int y)
{
    if (y==0) return 1;
    if (y%2==1) return (x*1ll*step(x,y-1))%MOD;
    int p=step(x,y/2);
    return (p*1ll*p)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int p=(step(2,m)-1+MOD)%MOD;
    int ans=step(p,n);
    cout<<ans;
}