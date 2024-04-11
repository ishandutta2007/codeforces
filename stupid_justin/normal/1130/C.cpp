
#include<bits/stdc++.h>
using namespace std;
int n;
int x[2],y[2]; 
char z[55][55];
int v[2][55][55];
int ans=INT_MAX;
void dfs(int a,int b,int c)
{
	if(v[c][a][b])
		return ;
	v[c][a][b]=1;
	if(z[a+1][b]=='0') 
		dfs(a+1,b,c);
	if(z[a][b+1]=='0')
		dfs(a,b+1,c);
	if(z[a-1][b]=='0')
		dfs(a-1,b,c);
	if(z[a][b-1]=='0')
		dfs(a,b-1,c); 
}
int main()
{
	cin>>n;
	for(int i=0;i<2;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
		scanf("%s",z[i]+1);
	for(int i=0;i<2;i++)
		dfs(x[i],y[i],i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(v[0][i][j]) 
			{
				for(int k=1;k<=n;k++)
					for(int l=1;l<=n;l++)
					{
						if(v[1][k][l]) 
							ans=min(ans,(i-k)*(i-k)+(j-l)*(j-l)); 
					}
			}
		}
	cout<<ans<<endl;
}