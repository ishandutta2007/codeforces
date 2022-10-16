#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=3e5+5;
const int M=5005;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
 
int n,id,l,r;
int a[N];
int ans[N];
vector<int> vec[N];
signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		rd(n);
		for (int i=1;i<=n;i++) vec[i].clear();
		for (int i=1;i<=n;i++) ans[i]=0;
		for (int i=1;i<=n;i++) rd(a[i]);
		for (int i=1;i<=n;i++) vec[a[i]].push_back(i);
		l=1,r=n,id=0;
        int k;
		for (k=1;k<=n;k++)
		{
			if (vec[k].size()==0){id=k-1;break;}
			if (vec[k].size()>1){id=k;break;}
			if (vec[k][0]==l){l++;continue;}
			if (vec[k][0]==r){r--;continue;}
			id=k;break;
		} 
        if (k==n+1) id=n;
		for (int i=n-id+1;i<=n-1;i++) ans[i]=1;
		if (vec[1].size()>0) ans[n]=1;
		ans[1]=1;
		for (int i=1;i<=n;i++) if (vec[i].size()!=1) ans[1]=0;
		for (int i=1;i<=n;i++) cout<<ans[i];cout<<endl;
	}
}