#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v[123];
bool solved[123];
int n,m,a[123],b[123];
int cnt=0;

inline bool solve(int peo,int lpeo,int npeo,int &p)
{
	p++;solved[npeo]=true;
	if(peo==npeo&&p%2)return false;
	else if(peo==npeo&&!(p%2))return true;
	else if(v[npeo][0]!=lpeo)return solve(peo,npeo,v[npeo][0],p);
	else if(v[npeo].size()==1)return true;
	else return solve(peo,npeo,v[npeo][1],p);
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		v[a[i]].push_back(b[i]);
		v[b[i]].push_back(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i].empty()||solved[i])continue;
		else
		{
			bool a;int p=0;
			a=solve(i,i,v[i][0],p);
			if(!a)cnt++;
		}
	}
	if((n-cnt)%2)cnt++;
	printf("%d\n",cnt);
	return 0;
}