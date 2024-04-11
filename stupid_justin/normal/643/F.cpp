#include<bits/stdc++.h>
#define rd(x) x=read()
#define int unsigned
#define endl "\n"
#define I inline
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int N=2e5+5;
int n,p,q,ans;
int C[N],mul[N];

signed main()
{
	rd(n);rd(p);rd(q);
	p=min(p,n-1);
	C[0]=1;
	for (int i=1;i<=p;i++)
	{
		mul[i]=n-i+1;int t=i;
		for (int j=1;j<=i && t!=1;j++) {int g=__gcd(t,mul[j]);t/=g;mul[j]/=g;}
		C[i]=1;
		for (int j=1;j<=i;j++) C[i]*=mul[j];
	}
	for (int i=1;i<=q;i++)
	{
		int tmp=0,TMP=1;
		for (int j=0;j<=p;j++) tmp+=C[j]*TMP,TMP*=i;
		ans^=tmp*i;
	}
	cout<<ans<<endl;
}