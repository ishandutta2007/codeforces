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
    const int N=35,mod=1e4+7,inf=2e9;
    int n,m,k;
    int a[N][N],b[N][N];
    int ansx[N][N],ansy[N][N];
    int stx,sty;
    inline int pow(int n)
    {
        int x=1;    
        while(n%2==0)
        {
            x<<=1;
            n>>=1;
        }
        return x;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T=1;
        while(T--)
        {
            cin>>n>>m;int sum=0;
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<n;++j)
                {
                    a[i][j]=pow(j)*pow(j);
                    ansx[i][j+1]=ansx[i][j]^a[i][j];
                    sum+=a[i][j];
                }
            }
            for(int j=1;j<=n;++j)
            {
                for(int i=1;i<n;++i)
                {
                    b[i][j]=2*pow(i)*pow(i);
                    ansy[i+1][j]=ansy[i][j]^b[i][j];
                    sum+=b[i][j];
                }
            }
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<n;++j)
                {
                    cout<<a[i][j];
                    if(j==n-1) cout<<endl;
                    else cout<<' ';
                }
            }
            for(int i=1;i<n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    cout<<b[i][j];
                    if(j==n) cout<<endl;
                    else cout<<' ';
                }
            }
            //cout<<sum<<"!!!"<<endl;
            stx=sty=1;
            //cout<<ansy[1][2]<<' '<<ansy[2][2]<<"!!"<<endl;
            while(m--)
            {
                int x;cin>>x;
                bool flag=0;
                for(int i=1;i<=n&&!flag;++i)
                {
                    for(int j=1;j<=n&&!flag;++j)
                    {
                        int l=sty,r=j;
                        if(l>r) swap(l,r);
                        int tmp=ansx[i][l]^ansx[i][r];
                        l=stx,r=i;
                        if(l>r) swap(l,r);
                        tmp^=ansy[l][j]^ansy[r][j];
                        //cout<<stx<<' '<<sty<<' '<<i<<' '<<j<<' '<<tmp<<"!!"<<endl;
                        if(tmp==x)
                        {
                            flag=1;
                            stx=i,sty=j;
                            cout<<i<<' '<<j<<endl;
                            break;
                        }
                    }
                }
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