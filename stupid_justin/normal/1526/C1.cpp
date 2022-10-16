#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=1e6+5;
const int M=70;
const int SZ=450;
const int mod=998244353;
const long double eps=1e-9;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
int n,ans,tot;
int a[N];
int sum[N];
multiset<int> S;
signed main()
{
	rd(n);for (int i=1;i<=n;i++) rd(a[i]);
	for (int i=1;i<=n;i++) if (a[i]>=0) sum[i]=sum[i-1]+a[i],ans++;else sum[i]=sum[i-1];
	for (int i=1;i<=n;i++) if (a[i]<0)
	{
		if (sum[i]+tot+a[i]>=0) S.insert(a[i]),tot+=a[i],ans++;else 
		{
			if (a[i]<(*S.begin())) continue;
			int x=*S.begin();S.erase(S.find(x));S.insert(a[i]);
			tot-=x;tot+=a[i];
		}
	}
	cout<<ans<<endl;
}