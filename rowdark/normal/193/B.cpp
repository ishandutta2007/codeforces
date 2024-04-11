#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

int n,u,r;

int a[4][31];

int b[31][31];

long long ans=1ULL<<63;

void Dfs(int depth,int lastoperation){
	if((depth&1)==(u&1))
	{
		long long nowval=0;
		for(int i=0;i<n;++i)
		{
			nowval+=b[depth][i]*a[2][i];
		}
		if(ans<nowval) ans=nowval;
	}
	if(depth==u) return;
	if(lastoperation!=1)
	{
		for(int i=0;i<n;++i)
		{
			b[depth+1][i]=b[depth][i]^a[1][i];
		}
		Dfs(depth+1,1);
	}
	for(int i=0;i<n;++i)
	{
		b[depth+1][i]=b[depth][a[3][i]]+r;
	}
	Dfs(depth+1,0);
}

int main() {
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
	cin>>n>>u>>r;
	for(int i=0;i<4;++i)
	{
		for(int j=0;j<n;++j)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;++i) b[0][i]=a[0][i],--a[3][i];
	Dfs(0,0);
	cout<<ans<<endl;
	cin>>n;
	return 0;
}