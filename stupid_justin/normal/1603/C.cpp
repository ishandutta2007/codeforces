#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define endl "\n"
using namespace std;
const int N=6e5+5;
const int M=605;
const int mod=998244353;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int a[N],f[N];
int n,T,ans,sum;
int main()
{
	int T;rd(T);while (T--)
	{
		rd(n);for (int i=1;i<=n;i++) rd(a[i]);
		ans=0,sum=0;
		for (int i=1;i<=n;i++)
        {
			f[i]=1;
			for (int j=i-1;j;j--)
            {
				int b=a[j+1]/f[j+1];
				if ((a[j]+f[j]-1)/f[j]<=b) break;
				int k=(a[j]+b-1)/b;
				sum=(sum+1ll*j*(k-f[j]))%mod;
				f[j]=k;
			}
			ans=(ans+sum)%mod;
		}
        cout<<ans<<endl;
	}
}
/*

*/