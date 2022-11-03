#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=20;

int n,m,mxchs=-10000,maxzt;
bool dir[maxn][maxn];
vector<string> shd;
map<string,int> hom;
string c[maxn];

void dfs(int zhuangt,int chsd,int nowd)
{
	if(nowd==n)
	{
		for(int i=0;i<n;i++)
		{
			if(zhuangt&(1<<i))
				for(int j=0;j<n;j++)
					if((zhuangt&(1<<j))&&dir[i][j])chsd=-10000;
		}
		if(chsd>mxchs)
		{
			mxchs=chsd;
			maxzt=zhuangt;
		}
		return;
	}
	else
	{
		dfs(zhuangt*2,chsd,nowd+1);
		dfs(zhuangt*2+1,chsd+1,nowd+1);
		return;
	}
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>c[i],hom[c[i]]=i;
	string junk1,junk2;
	for(int i=0;i<m;i++) cin>>junk1>>junk2,dir[hom[junk1]][hom[junk2]]=dir[hom[junk2]][hom[junk1]]=true;
	dfs(0,0,0);
	cout<<mxchs<<endl;
	for(int i=0;i<n;i++) if(maxzt&(1<<i)) shd.push_back(c[i]);
	sort(shd.begin(),shd.end());
	for(int i=0;i<mxchs;i++) cout<<shd[i]<<endl;
	return 0;
}