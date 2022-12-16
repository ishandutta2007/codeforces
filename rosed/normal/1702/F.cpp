#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
const int N=5e5+10,mod=1e9+7,inf=2e9;
int n,m;
int a[N],b[N];
multiset<int> q;
multiset<int>::iterator it;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int qwq;cin>>qwq;
    while(qwq--)
    {
        cin>>n;
        q.clear();
        for(int i=1;i<=n;++i) cin>>a[i];
        for(int i=1;i<=n;++i) cin>>b[i];
        for(int i=1;i<=n;++i)
        {
            while(a[i]%2==0) a[i]/=2;
            q.insert(a[i]);
        }
        sort(b+1,b+n+1);
        // for(int i=1;i<=n;++i)
        // {
        //     bool flag=0;
        //     for(int x=b[i];x<=inf;x*=2)
        //     {
        //         it=q.find(x);
        //         if(it==q.end()) continue;
        //         q.erase(it);
        //         flag=1;break;
        //     }
        //     if(flag) b[i]=0;
        // }
        for(int i=n;i>=1;--i)
        {
            bool flag=0;
            for(int x=b[i];x>0;x/=2)
            {
                //cout<<x<<' ';
                it=q.find(x);
                if(it==q.end()) continue;
                q.erase(it);
                flag=1;break;
            }
            //cout<<'\n';
            if(flag) b[i]=0;
        }
        bool flag=0;
        for(int i=1;i<=n;++i) flag|=(b[i]!=0);
        if(flag) cout<<"NO\n";
        else cout<<"YES\n"; 
    }
    return 0;
}
/*
1
5
2 2 4 4 4
28 46 62 71 98

*/