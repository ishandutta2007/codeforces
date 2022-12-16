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
	const int N=2e5+10,mod=1e9+7,inf=1e9+7;
	int n;
	char s[N]; 
	int p1[N],p2[N],num1,num2;
	inline bool check(int x)
	{
		int cnt1=1,cnt2=1;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='.') continue;
			if(i==p1[cnt1])
			{
				if(p1[cnt1]>p2[cnt2])
				{
					int zz=p1[cnt1]-p2[cnt2];
					if(zz>x)
					{
						return 0;
					}
					int k=x-2*zz;
					while(p2[cnt2]<=max(0ll,k)+p1[cnt1]) ++cnt2;
					while(2*(p2[cnt2]-p1[cnt1])+zz<=x) ++cnt2;
				}
				else if(p1[cnt1]<p2[cnt2])
				{
					while(p2[cnt2]<=x+p1[cnt1]) ++cnt2;
				}
				++cnt1;
				
			}
			if(cnt1==num1+1) break;
			if(cnt2==num2+1) break;
		}
		return cnt2==num2+1; 
	}
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		cin>>n;
		cin>>(s+1);
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='P')
			{
				p1[++num1]=i;
			}
			if(s[i]=='*')
			{
				p2[++num2]=i;
			}
		}
		p2[num2+1]=99999999;
		int l=1,r=2*n,ans=r;
		while(l<=r)
		{
			if(check(mid)) ans=mid,r=mid-1;
			else l=mid+1;
		}
		cout<<ans<<'\n';
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
19
**P.*..*..P..*.*P**

17
.*P*P**P**.**P...

*/