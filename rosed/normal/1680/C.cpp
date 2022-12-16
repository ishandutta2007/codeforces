#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char f=0,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=1e6+10,inf=2e9;
	int n,m,sum;
	char s[N];
	int pre[N],pre2[N];
	inline int check1(int x)
	{
		for(int l=1,r=x;r<=n;++l,++r)
		{
			while(pre2[r+1]-pre2[l-1]<=x&&r<n) ++r;
			if(pre[l-1]+pre[n]-pre[r]<=x) return 1;
		}
		return 0;
	}
	inline bool check2(int x)
	{
		int l=n,r=n;
		while(pre[l]>x&&l>0) --l;
		for(;l>=0;--l)
		{
			while(pre[n]-pre[r-1]+pre[l]<=x&&r>0) --r;
			int tmp=max(0ll,pre2[r]-pre2[l]);
			if(tmp<=x) return 1;
		}
		return 0;
	}
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>(s+1);
			n=strlen(s+1);
			int sum=0;
			for(int i=1;i<=n;++i)
			{
				pre[i]=pre[i-1]+(s[i]=='1');
				pre2[i]=pre2[i-1]+(s[i]=='0');
			}
			int l=0,r=n,ans1=n;
			while(l<=r)
			{
				if(check1(mid)) ans1=mid,r=mid-1;
				else l=mid+1;
			}
			l=0,r=n;
			int ans2=n;
			while(l<=r)
			{
				if(check2(mid)) ans2=mid,r=mid-1;
				else l=mid+1;
			}
			cout<<min(ans1,ans2)<<'\n';
		}
	}
}
signed main()
{
	red::main();
	return 0;
}

/*
1
0000111111

*/