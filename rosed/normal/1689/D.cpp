#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
#define y1 zmakioi
    const int N=1e6+10,mod=998244353,inf=2e9;
    int n,m,k;
    char a[1010][1010];
    int s1[N],s2[N];
    int num1,num2;
    int ans,posx,posy;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;cin>>skx;
        while(skx--)
        {
            cin>>n>>m;
            num1=num2=0;
            ans=inf;posx=posy=0;
            for(int i=1;i<=n;++i)
            {
                cin>>(a[i]+1);
                for(int j=1;j<=m;++j)
                {
                    if(a[i][j]=='B')
                    {
                        s1[++num1]=i+j;
                        s2[++num2]=i-j;
                    }
                }
            }
            sort(s1+1,s1+num1+1);
            sort(s2+1,s2+num2+1);
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=m;++j)
                {
                    int tmp1=i+j,tmp2=i-j;
                    int tmp=max(max(s1[num1]-tmp1,s2[num2]-tmp2),max(tmp1-s1[1],tmp2-s2[1]));
                    if(tmp<ans)
                    {
                        ans=tmp;
                        posx=i,posy=j;
                    }
                }
            }
            cout<<posx<<' '<<posy<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*


x y

x1>=x

y1>=y

dis=x1-x+y1-y=x1+y1-(x+y)

y1<y

dis=x1-x+y-y1=x1-y1-(x-y)

x1<x

y1>=y

dis=x-x1+y1-y=(x-y)-(x1-y1)

y1<y

dis=x-x1+y-y1=(x+y)-(x1+y1)

*/