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
    const int N=1e6+10,inf=2e9;
    int n,m,ans;
    int a[N];
    int b[N];
    map<int,int> q;
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int skx;
        cin>>skx;
        while(skx--)
        {
            cin>>n;
            bool flag=0;
            int num1=0,num2=0,num3=0;
            m=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                if(a[i]>0) ++num1;
                if(a[i]<0) ++num2;
                if(a[i]==0) ++num3;
                if(a[i]!=0) b[++m]=a[i];
            }
            if(num1>2||num2>2)
            {
                cout<<"NO\n";
                continue;
            }
            if(num3>0) --num3,b[++m]=0;
            if(num3>0) --num3,b[++m]=0;
            if(num3>0) --num3,b[++m]=0;
            sort(b+1,b+m+1);
            q.clear();
            for(int i=1;i<=m;++i) q[b[i]]=1;
             bool ok=1;
            for(int i=1;i<=m;++i)
            {
                for(int j=i+1;j<=m;++j)
                {
                    for(int k=j+1;k<=m;++k)
                    {
                       // cout<<b[i]<<' '<<b[j]<<' '<<b[k]<<"!!"<<endl;
                        if(!q[b[i]+b[j]+b[k]])
                        {
                            ok=0;
                            break;
                        }
                    }
                }
            }
            if(ok) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
2.25 10 100

*/