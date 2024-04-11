#include<bits/stdc++.h>
using namespace std;
namespace red{
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
	const int N=5e5+10,mod=1e9+7,inf=1e9;
	char s[N],t[N];
	int n,m;
	int l[N],r[N],pos[N];
	inline void workl(int *a)
	{
		for(int i=0;i<26;++i) pos[i]=-inf;
		int k=1;
		for(int i=1;i<=n;++i)
		{
			if(k<=m&&s[i]==t[k])
			{
				a[i]=k;
				pos[s[i]-'a']=k++;
				
			}
			else a[i]=pos[s[i]-'a'];
		}
	}
	inline void workr(int *a)
	{
		for(int i=0;i<26;++i) pos[i]=inf;
		int k=m;
		for(int i=n;i;--i)
		{
			if(k>0&&s[i]==t[k])
			{
				a[i]=k;
				pos[s[i]-'a']=k--;
			}
			else a[i]=pos[s[i]-'a'];
		}
	}
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		cin>>(s+1)>>(t+1);
		n=strlen(s+1),m=strlen(t+1);
		workl(l);
		workr(r);
		bool flag=1;
		for(int i=1;i<=n;++i)
		{
		//	cout<<l[i]<<' '<<r[i]<<"!!"<<'\n';
			flag&=(r[i]<=l[i]);	
		}
		if(flag) cout<<"Yes";
		else cout<<"No";
		cout<<'\n'; 
	}
}
signed main()
{
	red::main();
	return 0;
}
/*

kkkljkk
*/