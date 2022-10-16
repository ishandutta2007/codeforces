#include<bits/stdc++.h>
using namespace std;
constexpr int SZ=155;
struct mat
{
	array<bitset<SZ>,SZ> a;
	mat(int x=0)
	{
		for(int i=0;i<SZ;i++)
		{
			a[i][i]=x;
		}
	}
	bitset<SZ>& operator[](int x){return a[x];}
	const bitset<SZ> &operator[](int x)const{return a[x];}
	mat T()const
	{
		mat ret;
		for(int i=0;i<SZ;i++)
			for(int j=0;j<SZ;j++)
				ret[j][i]=a[i][j];
		return ret;
	}
	mat operator*(const mat &m)const
	{
		mat ret,mt=m.T();
		for(int i=0;i<SZ;i++)
			for(int j=0;j<SZ;j++)
				ret[i][j]=((a[i]&mt[j]).count()!=0);
		return ret;
	}
};
mat pw(mat x,int y)
{
	mat ret(1);
	while(y)
	{
		if(y&1)ret=ret*x;
		x=x*x;
		y>>=1;
	}
	return ret;
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<tuple<int,int,int>> eg;
	for(int i=1;i<=m;i++)
	{
		int u,v,d;
		cin>>u>>v>>d;
		eg.emplace_back(d,u,v);
	}
	eg.emplace_back(0,n,n);
	eg.emplace_back(1.01e9,0,0);
	sort(eg.begin(),eg.end());
	mat cur(1),mul;
	int pre=0;
	int l=0,r=-1;
	for(auto [d,u,v]:eg)
	{
//		cerr<<"edge "<<u<<' '<<v<<' '<<d<<endl;
		mat tmp=cur*pw(mul,d-pre);
		if(tmp[1][n])
		{
//			cerr<<"YES"<<endl;
			r=d-pre;
			break;
		}
		cur=tmp;
		pre=d;
		mul[u][v]=1;
	}
	if(r==-1)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	while(l<r)
	{
		int mid=(l+r)/2;
		mat tmp=cur*pw(mul,mid);
		if(tmp[1][n])r=mid;
		else l=mid+1;
	}
	cout<<pre+l<<endl;
	return 0;
}