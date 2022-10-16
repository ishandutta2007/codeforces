#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
int read(){int x=0,f=1;char c=getchar();while (c<'0' || c>'9') {if (c=='-') f=-1;c=getchar();}while (c>='0' && c<='9') x=x*10+c-'0',c=getchar();return x*f;}
const int N=1e6+5;
int a[N],n,l,r;
int ans=1e18;
int cnt=0;
char s[N];
void DOIT()
{
    rd(n);scanf("%s",s+1);
    ans=10000000;
    for (int c='a';c<='z';c++)
    {
        cnt=0;bool flag=1;
        // c 
        l=1;r=n;
        while (l<=r)
        {
            if (s[l]!=s[r])
            {
                if (s[l]==c) cnt++,l++;
                else if (s[r]==c) cnt++,r--;
                else {flag=0;break;}
            } else l++,r--;
        }
        if (flag) ans=min(ans,cnt);

    }

    if (ans==10000000) puts("-1");else cout<<ans<<"\n";

}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();

}
/*

*/