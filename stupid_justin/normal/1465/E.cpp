#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=2e6+5;
const int M=5005;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x);x=(x*x);y>>=1;}return ret;}

int x,n,y;
int a[N];
string s;
int cnt[N];
int ABS(int x){if (x<0) return -x;else return x;}
signed main()
{
	rd(n);rd(x);
	cin>>s;s=" "+s;
	for (int i=1;i<=n;i++) a[i]=ksm(2,s[i]-'a');
	x-=a[n];x+=a[n-1];
	x=ABS(x);
	for (int i=1;i<n-1;i++) cnt[s[i]-'a']++;
	for (int i=25;i>=0;i--)
	{
		x=ABS(x);
		if (x>=cnt[i]*(1LL<<i)) x-=cnt[i]*(1LL<<i);
		else 
		{
			int t=x/(1LL<<i);
			if ((cnt[i]-t)%2==0) x-=t*(1LL<<i);
			else x-=(t+1)*((1LL<<i));
		}
	}
	if (x==0) puts("Yes");
	else puts("No");
}