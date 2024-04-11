#include<bits/stdc++.h>
#define int long long 
#define ri int
#define rd(x) x=read()
using namespace std;
const int N=18;
const int M=505;
const int maxn=5e6+5;
const int mod=998244353;
const int inf=3e18;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int l,r;
inline int get(int x){if (x<10) return x;return x%10+get(x/10);}
int k,m,tot;
int a,b,c,d,e;
set<int> SS,S;
void out(int x){if (x<10) cout<<0;if (x<100) cout<<0;if (x<1000) cout<<0;cout<<x;}
void out(int x,int y){if (SS.find(x*10000+y)!=SS.end()) return;SS.insert(x*10000+y);out(x);out(y);cout<<"\n";tot++;if (tot==m) exit(0);}
void put(int y)
{
    if (k+y<10000 && k+y>=0) {out(k+y,e);if (e!=k+y) out(e,k+y);}
    if (y-k<10000 && k-y<=0) {out(y-k,e);if (e!=y-k)out(e,y-k);}
    if (k-y<10000 && k-y>=0) {out(k-y,e);if (e!=k-y)out(e,k-y);}
}
void solve3(int A,int B,int C){put((A+B)+C);put((A+B)-C);put((A+B)*C);put((A-B)+C);put((A-B)-C);put((A-B)*C);put((A*B)+C);put((A*B)-C);put((A*B)*C);put(A+(B+C));put(A+(B-C));put(A+(B*C));put(A-(B+C));put(A-(B-C));put(A-(B*C));put(A*(B+C));put(A*(B-C));put(A*(B*C));}
int op(int A,int B,int C){if (C==1) return A+B;if (C==2) return A-B;if (C==3) return A*B;}
void solve4(int A,int B,int C,int D,int E,int F,int G)
{
    put(op(op(op(A,B,E),C,F),D,G));
}
void solve(int x)
{
    S.clear();
    e=x;d=x%10;x/=10;c=x%10;x/=10;b=x%10;x/=10;a=x%10;x/=10;
    put(e);put((a*10+b)*(c*10+d));put((a*10+b)+(c*10+d));put((a*10+b)-(c*10+d));put((a*100+b*10+c)*(d));put((a*100+b*10+c)+(d));put((a*100+b*10+c)-(d));put((a)*(b*100+c*10+d));put((a)+(b*100+c*10+d));put((a)-(b*100+c*10+d));
    solve3(a*10+b,c,d);solve3(a,b*10+c,d);solve3(a,b,c*10+d);
    for (int i=1;i<=3;i++) for (int j=1;j<=3;j++) for (int k=1;k<=3;k++) 
    {
        solve4(a,b,c,d,i,j,k);
        solve4(b,c,a,d,i,j,k);
        solve4(b,c,d,a,i,j,k);
        solve4(b,c,a,d,i,j,k);
        put(op(op(a,b,i),op(c,d,j),k));
    }
}
signed main()
{
    rd(k);rd(m);
    for (int i=0;i<10000;i++) solve(i);    
}