#include<bits/stdc++.h>
#define int long long
#define ls (rt<<1)
#define rs (rt<<1|1)
#define pii pair<int,int>
#define fi first
#define se second
#define rd(x) x=read()
#define endl '\n'
using namespace std;

const int N=2e5+5;
const int mod=1e9+7;
const int inf=3e18;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,k,ans;
int a[N];
int v[N]; 

signed main()
{
	int T;cin>>T;while (T--)
	{
		rd(n);for (int i=1;i<=n;i++) rd(a[i]);
		for (int i=0;i<=100;i++) v[i]=0;
		for (int i=1;i<=n;i++) v[a[i]]++;
		for (int i=0;i<=100;i++) if (v[i]) {cout<<i<<" ";v[i]--;}
		for (int i=0;i<=100;i++) for (int j=1;j<=v[i];j++) cout<<i<<" ";cout<<endl;
	}
}