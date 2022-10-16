
#include<bits/stdc++.h>
#define endl "\n"
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=1e5+5;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

int a,b,c,d,ans;
signed main()
{
    int T;
    rd(T);
    while (T--)
    {
        rd(a);rd(b);rd(c);rd(d);
        if (a>b*c) {cout<<-1<<endl;continue;}
        int t=((a-1)/b)/d;
        ans=(-t)*(t+1)/2*b*d+a*(t+1);
        cout<<ans<<endl;
        
    }
}