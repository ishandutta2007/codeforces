#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
const int inf=1e18;
void solve()
{
    int n,pos;
    cin>>n>>pos;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    int nowl=pos,nowr=pos,sum=a[pos];
    bool t1=1,t2=1;
    int suml,sumr,minnl,minnr,tl,tr;
    while(nowl>1&&nowr<n)
    {
        if(t1) suml=0,minnl=0,tl=nowl-1;
        if(t2) sumr=0,minnr=0,tr=nowr+1;
        
        while(suml<=0&&tl>=1&&t1)
        {
            suml+=a[tl--];
            minnl=min(minnl,suml);
        }
        while(sumr<=0&&tr<=n&&t2)
        {
            sumr+=a[tr++];
            minnr=min(minnr,sumr);
        }
        if(minnl+sum>=0)
        {
            sum+=suml;
            nowl=tl+1;
            t1=1,t2=0;
        }
        else if(minnr+sum>=0)
        {
            sum+=sumr;
            nowr=tr-1;
            t1=0,t2=1;
        }
        else break;
    }
    if(nowl==1||nowr==n) cout<<"YES\n";
    else cout<<"NO\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}