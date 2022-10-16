#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=2e6+5;
const int M=5005;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x);x=(x*x);y>>=1;}return ret;}

int T,n,y;
int a[N];
string s;
int cnt[N];
int ABS(int x){if (x<0) return -x;else return x;}
signed main()
{
	rd(n);rd(T);
	cin>>s;s=" "+s;
	for (int i=n-1;i<=n;i++) a[i]=ksm(2,s[i]-'a');
	T-=a[n];T+=a[n-1];
	for (int i=1;i<n-1;i++) cnt[s[i]-'a']++;
	for (int i=25;i>=0;i--)
	{
		int p=(1LL<<i);
		T=ABS(T);
		if (T>=cnt[i]*p) T-=cnt[i]*p;// 
		else 
		{
			int t=T/p;// T  
			if ((cnt[i]-t)%2==0) T-=t*p;// 
			else T-=(t+1)*p;// p|T|>=p |T|<=p 
		}
	}
	if (T==0) puts("Yes");
	else puts("No");
}