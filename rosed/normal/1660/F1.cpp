#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
    const int N=2e5+10,mod=998244353,inf=2e9;
    int n,sum;
    char s[N];
    int a[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;sum=0;
            cin>>(s+1);
            for(int r=1;r<=n;++r)
            {
                for(int i=1;i<=r;++i) a[i]=(s[i]=='+');
                int s1=0,s2=0,s3=0;
                for(int l=r;l>=1;--l)
                {
                    if(a[l]) ++s1;
                    else ++s2;
                    if(a[l]==0&&a[l+1]==0&&l+1<=r)
                    {
                        ++s3;
                        a[l]=a[l+1]=1;
                    }
                    if(s1<=s2&&(s2-s1)%3==0) ++sum;
                }
                //cout<<sum<<"!!"<<endl;
            }
            cout<<sum<<'\n';
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
1 2 3 4

*/