#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0, f=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m;
int g[110][110];
int vote[110];
int ord[110];
int lhz;

int getd(int x)
{
	return g[x][n]-g[x][lhz];
}
bool cmp(int x,int y)
{
	return getd(x)>getd(y);
}
const int M = 100016, MOD = 1000000007;

vector<int> ans;
int main(void)
{
	#ifdef _LITTLEFALL_
	freopen("in.txt","r",stdin);
	#endif
	bool f=false;
	n=read();
	m=read();
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
		{
			g[i][j]=read();
			vote[j]+=g[i][j];
		}
	for (int i=1;i<=m;i++)
		ord[i]=i;
	for (lhz=1;lhz<=n-1;lhz++)
	{
		vector<int> v;
		sort(ord+1,ord+m+1,cmp);
		int tot=vote[n]-vote[lhz];
		for (int i=1;i<=m;i++)
			if (tot>0)
			{
				tot-=getd(ord[i]);
				v.push_back(ord[i]);
			}
		if (v.size()<ans.size() || f==false)
		{
			f=true;
			ans=v;
		}
	}
	cout<<ans.size()<<endl;
	for (auto p:ans)
		cout<<p<<' ';
	return 0;
}