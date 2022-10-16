#include<bits/stdc++.h>
using namespace std;
struct mat
{
	array<array<int,4>,4> a;
	mat(int x=0){for(int i=0;i<4;i++)for(int j=0;j<4;j++)a[i][j]=(i==j?x:0);}
	array<int,4>& operator[](int x){return a[x];}
	const array<int,4>& operator[](int x)const{return a[x];}
	mat operator*(const mat &m)const
	{
		mat ret;
		for(int i=0;i<4;i++)
			for(int k=0;k<4;k++)
				for(int j=0;j<4;j++)
					ret[i][j]+=a[i][k]*m[k][j];
		return ret;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	mat mul[256];
	mul['L'][0][0]=1;mul['L'][1][1]=1;mul['L'][2][2]=1;mul['L'][3][3]=1;mul['L'][3][1]=-1;
	mul['R'][0][0]=1;mul['R'][1][1]=1;mul['R'][2][2]=1;mul['R'][3][3]=1;mul['R'][3][1]=1;
	mul['U'][0][0]=1;mul['U'][1][1]=1;mul['U'][2][2]=1;mul['U'][3][3]=1;mul['U'][3][0]=-1;
	mul['D'][0][0]=1;mul['D'][1][1]=1;mul['D'][2][2]=1;mul['D'][3][3]=1;mul['D'][3][0]=1;
	mul['I'][0][0]=1;mul['I'][1][2]=1;mul['I'][2][1]=1;mul['I'][3][3]=1;
	mul['C'][0][2]=1;mul['C'][1][1]=1;mul['C'][2][0]=1;mul['C'][3][3]=1;
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		string s;
		cin>>n>>m;
		vector<vector<int>> a(n+5,vector<int>(n+5)),ans(n+5,vector<int>(n+5));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>a[i][j];
		cin>>s;
		mat cur(1);
		for(auto ch:s)
		{
			cur=cur*mul[ch];
		}
		for(int x=1;x<=n;x++)
			for(int y=1;y<=n;y++)
			{
				int t[4]={x,y,a[x][y],1},q[4]={0,0,0,0};
				for(int i=0;i<4;i++)
					for(int j=0;j<4;j++)
					{
						q[j]+=t[i]*cur[i][j];
					}
				for(int j=0;j<4;j++)
				{
					q[j]=(q[j]%n+n)%n;
					if(q[j]==0)q[j]=n;
				}
				ans[q[0]][q[1]]=q[2];
			}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<ans[i][j]<<' ';
			}
			cout<<"\n";
		}
	}
	
	return 0;
}