#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
const int N=5e5+10,mod=1e9+7;
int n,m;
int a[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int qwq;cin>>qwq;
    while(qwq--)
    {
        int x;cin>>x;
        int tmp=1;
        while(tmp*10<=x) tmp*=10;
        cout<<x-tmp<<'\n';
    }
    return 0;
}