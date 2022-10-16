#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=1e5+5;
const int M=5005;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
int a[N];
int n;
int prim[N],vis[N],cnt;
int ans;
int YUE[N],CNT;
int ANS=1;
int A(int x){cout<<"A "<<x<<endl;cin>>ans;}
int B(int x){cout<<"B "<<x<<endl;cin>>ans;}
int C(int x){cout<<"C "<<x<<endl;exit(0);}
signed main()
{
	rd(n);
	for (int i=2;i<=n;i++)
	{
		if (!vis[i]) prim[++cnt]=i;
		for (int j=1;j<=cnt;j++)
		{
			if (i*prim[j]>n) break;
			vis[i*prim[j]]=1;
			if (i%prim[j]==0) break;
		}
	}
	for (int i=1;i<=min(cnt,66LL);i++) 
	{
		B(prim[i]);
		A(prim[i]);
		int tmp=prim[i];
		while (ans==1)
		{
			tmp*=prim[i];
			YUE[++CNT]=prim[i];if (tmp>n) break;
			B(tmp);A(tmp);
		}
	}
	if (CNT!=0) for (int i=1;i<=CNT;i++) ANS*=YUE[i];
	if (ANS!=1)
	{
		for (int i=67;i<=cnt;i++)
		{
			A(prim[i]);
			if (ans!=1) C(ANS*prim[i]);
		}
	} else 
	{
		A(1);
		int tot=ans,K=0;
		for (int i=67;i<=cnt;i++)
		{
			B(prim[i]);K++;
			if (K%100==0 || i==cnt)
			{
				A(1);
				if (ans==tot-K) tot=ans,K=0;
				else for (int j=i-K+1;j<=i;j++) {A(prim[j]);if (ans==1) C(prim[j]);}
			}
		}
	}
	C(ANS);
}