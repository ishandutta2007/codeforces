#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    int minn=1e9;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        minn=min(minn,a[i]);
    }
    if(a[1]==minn)
    {
        cout<<"Bob\n";
    }
    else cout<<"Alice\n";

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
/*
1 1 1 
1 2 2 
2 2 2 
-> 2 2 1
-> 1 1 2
-> 1 0 2
-> 0 0 2

3 3 2
-> 2 2 3
-> 


2 2 
2 1 

2 3  -> 2 2
*/