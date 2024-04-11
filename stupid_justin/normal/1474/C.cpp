#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const signed N=3e6+5;
const int inf=0x3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

int n,m,x;
int a[N];
int v[N];
vector<pair<int,int> > cao;
void add(int x,int y)
{
	cao.push_back(make_pair(x,y));
}
signed main()
{
	int T;rd(T);
	while(T--)
	{
		rd(m);n=2*m;
		bool flag=0;
		for (int i=1;i<=n;i++) rd(a[i]);
		sort(a+1,a+n+1);
		for (int i=1;i<=n-1;i++)
		{
			//a[i]a[n]
			for (int j=1;j<=n;j++) v[a[j]]++;
			x=a[n]+a[i];
			cao.clear();
			bool fl=1;
			for (int j=n;j>=1;j--)
			{
				if (v[a[j]]==0) continue;
				if (v[x-a[j]]==0) {fl=0;break;}
				if (x-a[j]==a[j] && v[a[j]]==1){fl=0;break;}
				add(a[j],x-a[j]);
				v[a[j]]--;v[x-a[j]]--;
				x=a[j];
			}
			for (int j=1;j<=n;j++) v[a[j]]=0;
			if (fl)
			{
				flag=1;
				puts("YES");
				cout<<a[n]+a[i]<<"\n";
				for (int j=0;j<cao.size();j++) printf("%lld %lld\n",cao[j].first,cao[j].second);
				break;
			}
			
		}
		if (flag==0) puts("NO");
		for (int i=1;i<=n;i++) v[a[i]]=0;
		
		
	}
	
}