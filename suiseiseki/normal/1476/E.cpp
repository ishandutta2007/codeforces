#include <map>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;
int n,m,k;
string p[100010];
string s[100010];
vector<int> g[100010];
int deg[100010];
map<string,int> mp;
queue<int> q;
vector<int> ans;
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		mp[p[i]]=i;
	}
	for(int i=1;i<=m;i++){
		int mt;
		cin>>s[i]>>mt;
		vector<int> v;
		v.clear();
		for(int msk=0;msk<(1<<k);msk++){
			string tmp="";
			for(int j=0;j<k;j++){
				if(msk&(1<<j))
					tmp+=s[i][j];
				else
					tmp+='_';
			}
			if(mp.count(tmp))
				v.push_back(mp[tmp]);
		}
		bool flag=0;
		for(int j=0;j<v.size();j++){
			if(v[j]==mt)
				flag=1;
			else{
				g[mt].push_back(v[j]);
				deg[v[j]]++;
			}
		}
		if(!flag){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
		if(deg[i]==0)
			q.push(i);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		ans.push_back(x);
		for(int i=0;i<g[x].size();i++){
			deg[g[x][i]]--;
			if(deg[g[x][i]]==0)
				q.push(g[x][i]);
		}
	}
	if(ans.size()!=n){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}