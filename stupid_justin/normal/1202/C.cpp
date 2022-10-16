#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=2e5+5;
const int M=70;
const int SZ=450;
const int inf=0x3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,x,y,l,r,u,d,L,R,U,D;
string s;
signed main()
{
    int JYZ;rd(JYZ);
    while (JYZ--)
    {
        cin>>s;n=s.length();
        x=y=l=r=u=d=L=R=U=D=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='W') x++;if(s[i]=='S') x--;if(s[i]=='A') y++;if(s[i]=='D') y--;
			r=max(r,x);l=min(l,x);u=max(u,y);d=min(d,y);
			R=max(R,x-l);L=max(L,r-x);U=max(U,y-d);D=max(D,u-y);
		}
		x=max(R,L)+1;y=max(U,D)+1;
		int ans=x*y;
		if(x>2 && R!=L) ans=min(ans,(x-1)*y);
		if(y>2 && U!=D) ans=min(ans,(y-1)*x);
		cout<<ans<<endl;
    }
}
/*

*/