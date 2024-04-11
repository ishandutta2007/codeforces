#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int t,n,m,k[100001],st[100001],id[100001],bgn[100001],sum[100001],b[200001],sm[3][100001],a[100001];
bool cmp(int x,int y)
{
	return sum[x]*k[y]>sum[y]*k[x];
}
void solve()
{
	n=read();
	m=read();
	for(int i=0;i<n;i++)
		a[i]=read();
	int cnt=0;
	for(int i=0;i<m;i++)
	{
		k[i]=read();
		sum[i]=0;
		for(int l=0;l<k[i];l++)
		{
			b[cnt]=read();
			sum[i]+=b[cnt];
			cnt++;
		}
		st[i+1]=st[i]+k[i];
		id[i]=i;
	}
	sort(a,a+n,greater<int>());
	sort(id,id+m,cmp);
	for(int i=0;i<m;i++)
		bgn[id[i]]=i;
	for(int i=0;i<m;i++)
	{
		sm[0][i+1]=sm[0][i];
		if(a[i]*k[id[i]]>=sum[id[i]])
			sm[0][i+1]++; 
	}
	for(int i=0;i<m;i++)
	{
		sm[1][i+1]=sm[1][i];
		if(a[i]*k[id[i+1]]>=sum[id[i+1]])
			sm[1][i+1]++; 
	}
	for(int i=0;i<m;i++)
	{
		sm[2][i+1]=sm[2][i];
		if(a[i+1]*k[id[i]]>=sum[id[i]])
			sm[2][i+1]++; 
	}
	for(int i=0;i<m;i++)
		for(int j=0;j<k[i];j++)
		{
			int nwsum=sum[i]-b[j+st[i]];
			int nwk=k[i]-1;
			int l=0,r=m-1,mid;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(sum[id[mid]]*nwk<=nwsum*k[id[mid]])
					r=mid-1;
				else
					l=mid+1;
			}
//			cout<<l<<endl;
			int ed=l;
			if(sum[i]*nwk>nwsum*k[i])
				ed--;
			int bg=bgn[i];
			int nw=0;
			if(ed==bg)
				nw+=(sm[0][bg]+sm[0][m]-sm[0][bg+1]);
			if(ed<bg)
				nw+=(sm[0][ed]+sm[0][m]-sm[0][bg+1])+sm[2][bg]-sm[2][ed];
			if(ed>bg)
				nw+=(sm[0][bg]+sm[0][m]-sm[0][ed+1])+sm[1][ed]-sm[1][bg];
			if(nwsum<=nwk*a[ed])
				nw++;
			if(nw==m)
				putchar('1');
			else
				putchar('0');
		}
	cout<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}