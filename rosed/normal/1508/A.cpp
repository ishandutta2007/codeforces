#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=5e5+10,mod=998244353,inf=2e9;
    int n;
    char s[4][N];
    vector<int> q[2];
    inline void work(int a,int b,int opt)
    {
        int t1=1,t2=1;
        while(t1<=2*n&&t2<=2*n)
        {
            if(s[a][t1]==s[b][t2])
            {
                cout<<s[a][t1];
                ++t1,++t2;
            }
            else
            {
                while(s[a][t1]!=opt+'0'&&t1<=2*n) cout<<s[a][t1++];
                while(s[b][t2]!=opt+'0'&&t2<=2*n) cout<<s[b][t2++];
            }
            
        }
        while(t1<=2*n) cout<<s[a][t1++];
        while(t2<=2*n) cout<<s[b][t2++];
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            cin>>(s[1]+1)>>(s[2]+1)>>(s[3]+1);
            q[0].clear();q[1].clear();
            for(int i=1;i<=3;++i)
            {
                int sum=0;
                for(int j=1;j<=2*n;++j) sum+=(s[i][j]=='1');
                q[(sum>=n)].emplace_back(i);
            }
            if(q[0].size()>=2) work(q[0][0],q[0][1],0);
            else work(q[1][0],q[1][1],1);
            cout<<'\n'; 
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
1
6
001010100100
001100001011
000010010000


*/