#include<bits/stdc++.h>
#define int long long
#define ri register signed
#define rd(x) x=read()
using namespace std;
const int N=1e6+5;
const int M=1e6+5;
const int maxn=5e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,m;
void find(int x)
{
    if (x==-1) {puts("-1");exit(0);}
    if (x==1)  {puts("0 0");exit(0);}
    if (x==2)  {cout<<"0 "<<m<<endl;exit(0);}
    if (x==3)  {cout<<n<<" 0"<<endl;exit(0);}
    if (x==4)  {cout<<n<<" "<<m<<endl;exit(0);}
}
int exgcd(int a,int b,int &x,int &y) 
{
    if (!b) {x=1,y=0;return a;}
    int ret=exgcd(b,a%b,y,x);y-=a/b*x;
	return ret;
}
int x,y,dx,dy,xx,yy;
bool revx,revy;
signed main()
{
	rd(n);rd(m);rd(x);rd(y);rd(dx);rd(dy);
    if (dx*dy==0)
    {
        if (x>0 && y>0 && x<n &&y<m) find(-1);
        if (dy==-1 && x==0 || dx==-1 && y==0) find(1);
        if (dy==1 && x==0 || dx==-1 && y==m) find(2);
        if (dx==1 && y==0 || dy==-1 && x==n) find(3);
        if (dy==1 && x==n || dx==1 && y==m) find(4);
        find(-1);
    }
    
    if (dx==-1) revx=1,x=n-x;
    if (dy==-1) revy=1,y=m-y;
    int a,b,c;
    c=exgcd(n,m,a,b);
    if ((x-y)%c) find(-1);
    a*=(x-y)/c,b*=(x-y)/c;
    int m1=m/c;
    int A=(a%m1+m1-1)%m1+1;
    int B=(x-y-A*n)/m;B*=-1;
    if (A&1) xx=n-xx;if (B&1) yy=m-yy;
    if (revx) xx=n-xx;if (revy) yy=m-yy;
    cout<<xx<<" "<<yy<<endl;
}