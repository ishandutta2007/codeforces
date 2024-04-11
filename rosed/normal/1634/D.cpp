#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=201314,inf=2e9;
    int q1,q2,ans,x,y,pos1,pos2;
    int maxn1,maxn2;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            int n;cin>>n;
            bool flag1=0,flag2=0;
            q1=1,q2=2;
            cout<<"? 1 2 3"<<endl;
            cin>>maxn1;pos1=3;
            for(int i=4;i<=n;++i)
            {
                cout<<"? 1 2 "<<i<<endl;
                cin>>x;
                if(x!=maxn1) flag1=1;
                if(x>maxn1) maxn1=x,pos1=i;
            }
            q1=pos1;
            cout<<"? 1"<<' '<<q1<<' '<<q2<<endl;
            cin>>maxn2;pos2=1;
            for(int i=2;i<=n;++i)
            {
                if(i==q1||i==q2) continue;
                cout<<"? "<<q1<<' '<<q2<<' '<<i<<endl;
                cin>>x;
                if(x!=maxn2) flag2=1;
                if(x>maxn2) maxn2=x,pos2=i;
            }
            if(!flag1&&maxn1>=maxn2) cout<<"! 1 2"<<endl;
            else if(!flag2) cout<<"! "<<q1<<' '<<q2<<endl;
            else cout<<"! "<<pos1<<' '<<pos2<<endl;
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*

0 9 7 5 9 8 7 0 9 3

*/