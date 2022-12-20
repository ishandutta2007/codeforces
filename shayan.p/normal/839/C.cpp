#include<bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long double ld;
const int maxn=1e5+10;
vector<int>v[maxn];
ld dfs(int id=1,int par=-1)
{
	double ans=0;
	for(int i=0;i<v[id].size();i++)
	{
		int y=v[id][i];
		if(y==par)continue;
		ans+=dfs(y,id);
	}
	if(v[id].size()==1&&v[id][0]==par)return 0;
	return (ld(ans)/ld(v[id].size()-(par!=-1)))+1;
}
int main()
{
	int n;cin>>n;
	if(n==1){cout<<0;return 0;}
	for(int i=0;i<n-1;i++){int a,b;cin>>a>>b;v[a].PB(b);v[b].PB(a);}
	cout<<setprecision(9)<<fixed;
	cout<<dfs();
}