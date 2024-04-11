#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define M1 1000000007
#define M2 1000000013
pair<int,int> Hash(vector<int>& vec)
{
	long long h1=0,h2=0;
	long long p1=1,p2=1;
	for (int i=0;i<vec.size();i++)
	{
		h1+=(vec[i]*p1)%M1;
		h1%=M1;
		h2+=(vec[i]*p2)%M2;
		h2%=M2;
		p1=(p1*31)%M1;
		p2=(p2*29)%M2;
	}
	int x=h1,y=h2;
	return make_pair(x,y);
}
pair<int,int> all[3000000];
vector<int> adj[3000000];
int main()
{
    int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int num=0;
	for (int i=1;i<=n;i++)
	{
		sort(adj[i].begin(),adj[i].end());
		all[num++]=Hash(adj[i]);
		adj[i].push_back(i);
		sort(adj[i].begin(),adj[i].end());
		all[num++]=Hash(adj[i]);
	}
	sort(all,all+num);
	long long cur=1;
	long long ret=0;
	for (int i=1;i<num;i++)
	{
		if (all[i]==all[i-1])cur++;
		else ret+=(cur*(cur-1)/2),cur=1;
	}
	ret+=(cur)*(cur-1)/2;
	cout<<ret<<endl;
}