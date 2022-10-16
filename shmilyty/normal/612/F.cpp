#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
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
int n,s,a[2001],lef[2001],rig[2001],f[2001][2][2001],par[2001][2][2001],wth[2001][2][2001];
vector<int> u,res,v[2001];
int dis(int a,int b)
{
	if(a<=b)
		return b-a;
	return n+b-a;
}
int best(int a,int b)
{
	return min(dis(a,b),dis(b,a));
}
void get(int i,int f,int k)
{
	if(i<0)
		return ;
	if(f==0)
	{
		int j=par[i][f][k];
		get(i-1,1,j);
		if(best(j,k)==dis(j,k))
			res.push_back(dis(j,k));
		else
			res.push_back(-dis(k,j));
	}
	elif(par[i][f][k]==k)
		get(i,0,k);
	else
	{
		int j=par[i][f][k];
		get(i,0,j);
		int n=v[i].size();
		int ki=lower_bound(v[i].begin(),v[i].end(),k)-v[i].begin();
		vector<int> tmp;
		if(wth[i][f][k]==-1)
		{
			for(int z=1;z<=n;z++)
				tmp.push_back(v[i][(ki+z)%n]);
			int ji;
			for(int z=0;z<tmp.size();z++)
				if(tmp[z]==j)
				{
					ji=z;
					break;	
				}	
			int lst=j;
			for(int z=ji-1;z>=0;z--)
			{
				res.push_back(-dis(tmp[z],lst));
				lst=tmp[z];
			}
			for(int z=ji+1;z<tmp.size();z++)
			{
				res.push_back(dis(lst,tmp[z]));
				lst=tmp[z];
			}
		} 
		else
		{
			for(int z=0;z<n;z++)
				tmp.push_back(v[i][(ki+z)%n]);
			int ji;
			for(int z=0;z<tmp.size();z++)
				if(tmp[z]==j)
				{
					ji=z;
					break;
				}
			int lst=j;
			for(int z=ji+1;z<tmp.size();z++)
			{
				res.push_back(dis(lst,tmp[z]));
				lst=tmp[z];
			}
			for(int z=ji-1;z>=0;z--)
			{
				res.push_back(-dis(tmp[z],lst));
				lst=tmp[z];
			}
		}
	}
}
signed main()
{
	n=read();
	s=read()-1;
	for(int i=0;i<n;i++)
	{
		a[i]=read();
		u.push_back(a[i]);
	}
	sort(u.begin(),u.end());
	u.erase(unique(u.begin(),u.end()),u.end());
	for(int i=0;i<n;i++)
	{
		a[i]=lower_bound(u.begin(),u.end(),a[i])-u.begin();
		v[a[i]].push_back(i);
	}
	for(int i=0;i<n;i++)
		if(v[a[i]].size()>1)
		{
			int m=lower_bound(v[a[i]].begin(),v[a[i]].end(),i)-v[a[i]].begin();
			(m+=v[a[i]].size()-1)%=v[a[i]].size();
			lef[i]=v[a[i]][m];
			(m+=2)%=v[a[i]].size();
			rig[i]=v[a[i]][m];
		}
	fill((int*)f,(int*)f+2001*2*2001,INF);
	for(int i:v[0])
	{
		f[0][0][i]=best(s,i);
		par[0][0][i]=s;			
	}
	for(int i=0;i<u.size();i++) 
	{
		for(int j:v[i]) 
		{
			if(v[i].size()==1) 
			{ 
				f[i][1][j]=f[i][0][j]; 
				par[i][1][j]=j; 
			}
			else 
			for(int k:v[i]) 
				if(k!=j)
				{
					int cand=f[i][0][j]+2*dis(rig[k],j)+dis(j,k);
					if(cand<f[i][1][k]) 
					{
						f[i][1][k]=cand; 
						par[i][1][k]=j; 
						wth[i][1][k]=-1;
					}
					cand=f[i][0][j]+2*dis(j,lef[k])+dis(k, j);
					if(cand<f[i][1][k]) 
					{
						f[i][1][k]=cand; 
						par[i][1][k]=j; 
						wth[i][1][k]=1;
					}
				}
		}
		for(int j:v[i]) 
			for(int k:v[i+1]) 
			{
				int cand=f[i][1][j]+best(j,k);
				if(cand<f[i+1][0][k]) 
				{
					f[i+1][0][k]=cand; 
					par[i+1][0][k]=j;
				}
			}
	}
	int ans=INF,t;
	for(int j=0;j<n;j++)
		if(f[u.size()-1][1][j]<ans) 
		{ 
			ans=f[u.size()-1][1][j]; 
			t=j;
		}
	cout<<ans<<endl;
	get(u.size()-1,1,t);
	for(int i:res)
		if(i<0)
			cout<<i<<endl;
		else
			cout<<"+"<<i<<endl; 
	return 0;
}