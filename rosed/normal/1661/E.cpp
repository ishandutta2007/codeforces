#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=1e6+10,mod=1e9+7,inf=INT_MAX;
	int n,m;
	int a[N];
	char s[4][N];
	int pre[N];
	int cnt1[N],cnt2[N];
	int nxt[N];
	int ret[N];
	int f[N];
	inline int find(int k){return f[k]==k?k:f[k]=find(f[k]);}
	inline bool merge(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y) return 0;
		f[x]=y;
		return 1;
	}
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		cin>>n;
		for(int i=1;i<=3*n;++i) f[i]=i;
		for(int i=0;i<3;++i) cin>>(s[i]+1);
		for(int i=1;i<=n;++i)
		{
			pre[i]=pre[i-1];
			for(int k=0;k<3;++k) pre[i]+=(s[k][i]=='1');
			//cout<<pre[i]<<' ';
		}
		//cout<<endl;
		for(int i=1;i<=n;++i)
		{
			for(int k=0;k<3;++k)
			{
				if(k<2&&s[k][i]=='1'&&s[k+1][i]=='1'&&merge(k*n+i,k*n+n+i))
				{
					++cnt1[i];
				}
				if(i>1&&s[k][i]=='1'&&s[k][i-1]=='1'&&merge(k*n+i,k*n+i-1))
				{
					++cnt2[i-1];
				}
			}
		}
		for(int i=1;i<=n;++i) cnt1[i]+=cnt1[i-1],cnt2[i]+=cnt2[i-1];
		for(int i=n;i>=1;--i)
		{
			bool flag=(s[0][i]=='1'&&s[1][i]=='0'&&s[2][i]=='1');
			if(flag) nxt[i]=nxt[i+1]+1;
			else nxt[i]=0;
		}
		cin>>m;
		for(int i=1;i<=m;++i)
		{
			int l,r;
			cin>>l>>r;
			int nxt101=l+nxt[l];
			if(nxt101>r)
			{
				cout<<2<<'\n';
				continue;
			}
			int tot=pre[r]-pre[nxt101-1];
			int cnt=(cnt1[r]-cnt1[nxt101-1])+(cnt2[r-1]-cnt2[nxt101-1]);
			int ret=tot-cnt;
			//cout<<r<<' '<<l-1<<' '<<pre[r]<<' '<<pre[l-1]<<"!!!\n";
			if(nxt101!=l)
			{
				if(s[0][nxt101]=='1'&&s[1][nxt101]=='1'&&s[2][nxt101]=='1');
				else if(s[0][nxt101]=='0'&&s[2][nxt101]=='0') ret+=2;
				else ++ret;
			}
			cout<<ret<<'\n';
		}

	}
}
signed main()
{
	red::main();
	return 0;
}
/*
12
100101011101
110110010110
010001011101
1
8 11

5
11101
10110
11101
1
1 4

*/