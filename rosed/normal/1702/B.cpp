#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
const int N=5e5+10,mod=1e9+7;
int n,m;
char s[N];
char a[3];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int qwq;cin>>qwq;
    while(qwq--)
    {
        cin>>(s+1);
        n=strlen(s+1);
        int sum=1,k;
        a[0]=a[1]=a[2]=0;
        a[k=0]=s[1];
        for(int i=2;i<=n;++i)
        {
            bool flag=0;
            for(int j=0;j<=k;++j) flag|=(a[j]==s[i]);
            if(flag) continue;
            if(k==2)
            {
                ++sum;
                a[k=0]=s[i];
            }
            else a[++k]=s[i];
        }
        cout<<sum<<'\n';
    }
    return 0;
}