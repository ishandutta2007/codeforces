/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1100;
int T,n,a[N][N],b[N][N],vi[N][N],op[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) a[i][j]=read(),vi[i][j]=op[i][j]=0;
		vector <pair<int,int> > x,y;
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++)
		{
			if ((i+j)&1) x.emplace_back(i,j);
			else y.emplace_back(i,j);
		}
		auto cmp=[](pair<int,int> a,pair<int,int> b){
			int A=a.first+a.second,B=b.first+b.second;
			if (A!=B) return A<B;
			return a.first<b.first;
		};
		sort(y.begin(),y.end(),cmp);
		sort(x.begin(),x.end(),cmp);
		auto f=[](vector<pair<int,int> > y)
		{
			for (auto [a,b]:y)
			{
				bool bl=1;
				for (int i=0;i<4;i++)
				{
					int tx=a+dx[i],ty=b+dy[i];
					if (tx<=0||ty<=0||tx>n||ty>n) continue;
					if (op[tx][ty]) bl=0;
				}
				if (bl)
				{
					vi[a][b]=1;
					for (int i=0;i<4;i++)
					{
						int tx=a+dx[i],ty=b+dy[i];
						if (tx<=0||ty<=0||tx>n||ty>n) continue;
						op[tx][ty]^=1;
					}
				}
			}
		};
		f(x),f(y);
		int ans=0;
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (vi[i][j]) ans^=a[i][j];
		printf("%d\n",ans);
	}
}