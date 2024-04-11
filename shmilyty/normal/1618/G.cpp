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
int n,N,q,cnt,res,a[200001],b[400001],ans[200001],t[400001],to[400001],from[400001];
array<int,2> qry[200001],c[400001];
map<int,vector<int>> v;
int ask(int l,int r)
{
	return t[r]-t[l-1];
}
int val(int r,int k)
{
	return b[r]-b[r-k];
}
signed main()
{
	n=read();
	N=read()+n;
	q=read();
	for(int i=1;i<=n;i++)
		a[i]=b[i]=read();
	for(int i=n+1;i<=N;i++)
		b[i]=read();
	for(int i=1;i<=q;i++)
		qry[i]={read(),i};
	sort(a+1,a+1+n);
	sort(b+1,b+1+N);
	sort(qry+1,qry+1+q);
	for(int i=1,l=1;i<=N&&l<=n;i++)
		if(b[i]==a[l])
		{
			l++;
			t[i]++;
		}
	for(int i=1;i<=N;i++)
		if(i!=1)
			v[b[i]-b[i-1]].push_back(i);
	for(int i=1;i<=N;i++)
		b[i]+=b[i-1];
	sort(a+1,a+1+n);
	for(int i=1;i<=N;i++)
		t[i]+=t[i-1];
	for(int i=1;i<=N;i++)
	{
		to[i]=from[i]=i;
		res+=val(i,ask(i,i));
	}
	qry[0][0]=-1;
	auto it=v.begin();
	for(int i=1;i<=q;i++)
	{
		while(it!=v.end()&&it->first<=qry[i][0])
		{
			for(int j:it->second)
			{
				res-=val(j-1,ask(from[j-1],j-1));
				res-=val(to[j],ask(j,to[j]));
				to[from[j-1]]=to[j];
				from[to[j]]=from[j-1];
				res+=val(to[j],ask(from[j-1],to[j]));
				from[j-1]=to[j]=0;
			}
			it++;
		}
//		if(n==100)
//		{
//			cout<<qry[i][0]<<" "<<qry[i][1]<<" "<<res<<endl;
//			return 0;
//		}
		ans[qry[i][1]]=res;
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<'\n';
	return 0;
}