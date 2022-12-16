#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
#define y1 uuuu
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n,m;
        cin>>n>>m;
        string s;cin>>s;
        int sum=0;
        vector<int> cnt(2*n+1);
        for(int i=0;i<n;++i)
        {
            if(s[i]=='0') ++sum;
            else --sum;
            ++cnt[n+sum];
        }
        if(n+m<=2*n&&n+m>=0&&sum==0&&cnt[n+m]>0)
        {
            cout<<"-1\n";
            return;
        }
        if(sum==0)
        {
            cout<<0<<'\n';
            return;
        }
        //cout<<sum<<"!!"<<endl;
        int now=0;
        if(now+n<m&&sum>0) now+=(m-n+(sum-1))/sum*sum;
        if(now-n>m&&sum<0) now+=(-m-n-sum-1)/abs(sum)*sum;
        //cout<<now<<"!!"<<endl;
        int ans=0;
        if(now==m) ++ans;
        while(1)
        {
            int t=m-now;
            if(n+t>2*n||n+t<0) break;
            ans+=cnt[n+t];
            now+=sum;
            //cout<<now<<' '<<ans<<"!!!"<<endl;
        }
        cout<<ans<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*
0011100111
0
001
0011100

001010010100101
00
0010
001010
00101001
0010100101

*/