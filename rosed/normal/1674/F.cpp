#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=1000+10,mod=1e4+7,inf=2e9;
    int n,m,k,tot,sum;
    int a[N];
    char s[N][N];
    typedef pair<int,int> pr;
    inline int id(int x,int y)
    {
        return (y-1)*n+x;
    }
    inline pr di(int num)
    {
        int x=(num-1)/n+1,y=num%n;
        if(!y) y=n;
        return pr(y,x);
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T=1;
        while(T--)
        {
            cin>>n>>m>>k;
            for(int i=1;i<=n;++i)
            {
                cin>>(s[i]+1);
                for(int j=1;j<=m;++j)
                {
                    tot+=(s[i][j]=='*');
                }
            }
            sum=tot;
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=m;++j)
                {
                    if(s[i][j]=='*')
                    {
                        if(id(i,j)<=tot) --sum;
                    }
                }
            }
            for(int i=1;i<=k;++i)
            {
                int x,y;
                cin>>x>>y;
                if(s[x][y]=='*')
                {
                    if(id(x,y)>tot) --sum;
                    s[x][y]='.';
                    pr tmp=di(tot);
                    //cout<<sum<<"!!!!!!!!!!!!!!"<<'\n';
                    //cout<<tmp.first<<' '<<tmp.second<<"!!"<<'\n';;
                    --tot;
                    if(s[tmp.first][tmp.second]=='*') ++sum;
                }
                else
                {
                    ++tot;
                    if(id(x,y)>tot) ++sum;
                    pr tmp=di(tot);
                    if(s[tmp.first][tmp.second]=='*') --sum;
                    s[x][y]='*';
                    //cout<<tmp.first<<' '<<tmp.second<<"!!"<<endl;
                }
                // for(int i=1;i<=n;++i)
                // {
                //     for(int j=1;j<=m;++j)
                //     {
                //         cout<<s[i][j]<<" \n"[j==m];
                //     }
                // }
                cout<<sum<<'\n';
            }
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*


*/