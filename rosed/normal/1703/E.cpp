#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
const int N=5e5+10,inf=2e9;
int n,m;
int a[N];
char s[110][110];
bool vis[110][110];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int qwq;
	cin>>qwq;
	while(qwq--)
	{
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			cin>>(s[i]+1);
			for(int j=1;j<=n;++j) vis[i][j]=0;
		}
		if(n%2==0)
		{
			for(int i=1;i<=n/2;++i)
			{
				for(int j=1;j<=n/2;++j)
				{
					int tx1=i,ty1=j;
					int tx2=ty1,ty2=n-tx1+1;
					int tx3=ty2,ty3=n-tx2+1;
					int tx4=ty3,ty4=n-tx3+1;
					int sum=(s[tx1][ty1]=='1')+(s[tx2][ty2]=='1')+(s[tx3][ty3]=='1')+(s[tx4][ty4]=='1');
					if(vis[tx1][ty1]||vis[tx2][ty2]||vis[tx3][ty3]||vis[tx4][ty4]) continue;
					vis[tx1][ty1]=vis[tx2][ty2]=vis[tx3][ty3]=vis[tx4][ty4]=1;
					ans+=min(sum,4-sum);
				}
			}
		}
		else
		{
			for(int i=1;i<=n/2+1;++i)
			{
				for(int j=1;j<=n/2+1;++j)
				{
					int tx1=i,ty1=j;
					int tx2=ty1,ty2=n-tx1+1;
					int tx3=ty2,ty3=n-tx2+1;
					int tx4=ty3,ty4=n-tx3+1;
					int sum=(s[tx1][ty1]=='1')+(s[tx2][ty2]=='1')+(s[tx3][ty3]=='1')+(s[tx4][ty4]=='1');
					if(vis[tx1][ty1]||vis[tx2][ty2]||vis[tx3][ty3]||vis[tx4][ty4]) continue;
					vis[tx1][ty1]=vis[tx2][ty2]=vis[tx3][ty3]=vis[tx4][ty4]=1;
					// cout<<tx1<<' '<<ty1<<"!!"<<endl;
					// cout<<tx2<<' '<<ty2<<"!!"<<endl;
					// cout<<tx3<<' '<<ty3<<"!!"<<endl;
					// cout<<tx4<<' '<<ty4<<"!!"<<endl<<"---"<<endl;
					ans+=min(sum,4-sum);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}