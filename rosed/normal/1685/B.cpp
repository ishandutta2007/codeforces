#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,inf=2e9;
	int n,m;
	int a,b,c,d;
	char s[N];
	vector<int> q[2];
//	int dp[N];
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>a>>b>>c>>d;int e=0;
			cin>>(s+1);
			n=strlen(s+1);
			q[0].clear(),q[1].clear();
			bool flag=1;
			s[n+1]=0;
			//for(int i=0;i<=n;++i) dp[i]=0;
			for(int i=1;i<=n;++i)
			{
				int j=i;
				while(s[j+1]!=s[j]&&j<n) ++j;
				if(s[i]==s[j])
				{
					if(s[i]=='A') --a;
					else --b;
					//q.emplace_back((j-i)/2);
					e+=(j-i)/2;
				}
				else
				{
					if(s[i]=='A')
					{
						int tmp=(j-i+1)/2;
						c-=tmp;
						q[0].emplace_back(tmp);
					}
					else
					{
						int tmp=(j-i+1)/2;
						d-=tmp;
						q[1].emplace_back(tmp);
					}
				}
				i=j;
			}
			//cout<<a<<' '<<b<<' '<<c<<' '<<d<<"!"<<endl;
			sort(q[0].begin(),q[0].end());
			reverse(q[0].begin(),q[0].end());
			sort(q[1].begin(),q[1].end());
			reverse(q[1].begin(),q[1].end());

			if(c<0&&d>0)
			{
				for(int t:q[0])
				{
					if(a<=0||b<=0||d<=0) break;
					int tmp=min(t,min(-c,d+1));
					--a,--b;
					c+=tmp,d-=tmp-1;
				}
			}
			if(d<0&&c>0)
			{
				for(int t:q[1])
				{
					if(a<=0||b<=0||c<=0) break;
					int tmp=min(t,min(-d,c+1));
					--a,--b;
					d+=tmp,c-=tmp-1;
				}
			}
			//cout<<a<<' '<<b<<' '<<c<<' '<<d<<"!!"<<endl;
			if(c<0)
			{
				if(a>0&&b>0)
				{
					if(min(a,b)<-c) flag=0;
					else a+=c,b+=c,c=0;
				}
				else flag=0;
			}
			if(d<0)
			{
				if(a>0&&b>0)
				{
					if(min(a,b)<-d) flag=0;
					else a+=d,b+=d,d=0;
				}
				else flag=0;
			}
			//cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<"!"<<endl;
			e-=c+d;c=d=0;
			if(a==b&&a==e&&a>=0&&e>=0)
			{
				a=0,b=0;
			}
			else flag=0;
			//cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
			if(!a&&!b&&!c&&!d); else flag=0;
			if(flag) cout<<"YES\n";
			else cout<<"NO\n";
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
1 0 1 1
ABAAB

1
1 1 0 1
ABAB

1
2 3 5 4
A ABA AB BABA A ABAB BAB B BAB B

1
1 1 2 3
ABABABBAABAB

B AB A BA BA B


ABABAB BA ABAB

A BA B ABAB
*/