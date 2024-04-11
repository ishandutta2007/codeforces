#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=6e5+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
const double k=0.5;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int P,l,r;
string ans;
int cnt;
int JYZ;
unsigned seed=std::chrono::system_clock::now().time_since_epoch().count();
mt19937 rnd(seed);
void ask(int x)
{
    cout<<"? "<<x<<endl;cin>>ans;;
    if (ans=="Lucky!") P+=x,l=max(x,l);
    else P-=x,r=min(r,x-1);
}
void solve()
{
    // l  r 
    if (l==r) {cout<<"! "<<l<<endl;return;}
    if (r==l+1) {while (P<r) ask(l);ask(r);solve();return;}
    int L=(r-l+1);int q=l+k*L*P/(P+r)+1;q=max(min(q,P),l);ask(q);solve();
}

void DOIT()
{
    l=1;r=1e14;P=1;cnt=0;
    while (1)
    {
        if (P>r) {r=1e14;l=P/2;break;}
        cout<<"? "<<P<<endl;cin>>ans;
        if (ans=="Lucky!") P+=P;else 
        {r=P-1,l=P/2,P=0;break;}
    }
    if (l==0) {cout<<"! 0"<<endl;return;}
    solve();
}
signed main()
{
    rd(JYZ);for (int i=1;i<=JYZ;i++) DOIT();
}
/*
*/