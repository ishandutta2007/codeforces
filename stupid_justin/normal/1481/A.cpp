#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=5005+5;
const int M=5005;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
 
int n,x,y;
int u,d,r,l;
string s;
bool f1,f2;
signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		rd(x);rd(y);cin>>s;
		n=s.length();
		u=d=r=l=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='U') u++;
			if (s[i]=='D') d++;
			if (s[i]=='L') l++;
			if (s[i]=='R') r++;
		}
		if (x<0) f1=(l>=-x);else f1=(r>=x);
		if (y<0) f2=(d>=-y);else f2=(u>=y);
		if (f1 && f2) puts("YES");
		else puts("NO");
	}
}