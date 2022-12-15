#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
void solve()
{
    int n;
    cin>>n;
    typedef array<int,2> pr;
    vector<pr> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i][0];
        a[i][1]=a[i][0];
    }
    vector<int> b(n);
    sort(a.begin(),a.end(),[&](pr a,pr b){
        return a[0]>b[0];
    }); 
    int pos=0;
    while(a[pos][0]&&pos<n)
    {
        b[pos]=a[pos][1];
        int S=(1ll<<32)-1;
        S^=a[pos][0];
        ++pos;
        for(int j=pos;j<n;++j) a[j][0]&=S;
        sort(a.begin()+pos,a.end(),[&](pr a,pr b){
        return a[0]>b[0];
    }); 
    }
    while(pos<n) b[pos]=a[pos][1],++pos;
    for(int i=0;i<n;++i) cout<<b[i]<<" \n"[i==n-1];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}