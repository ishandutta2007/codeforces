#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int N=200200;
int n,m;
map<vector<int>,int>mp;
vector<int>g[N];
int cmp[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		 int a,b;
		 cin>>a>>b;
		 --a,--b;
		 if(b>=a)g[a].push_back(b-a);
		 else g[a].push_back(b-a+n);
		 if(a>=b)g[b].push_back(a-b);
		 else g[b].push_back(a-b+n);
	}
	for(int i=0;i<n;++i)sort(g[i].begin(),g[i].end());
	int c=0;
	for(int i=0;i<n;++i){
		if(mp.count(g[i]))cmp[i]=mp[g[i]];
		else cmp[i]=mp[g[i]]=c++;
		//cerr<<cmp[i]<<'\n';
	}
	for(int i=1;i<n;++i){
		if(n%i)continue;
		bool ok=true;
		for(int j=0;j<n;++j){
			int j1=(j+i);
			if(j1>=n)j1-=n;
			if(cmp[j]!=cmp[j1]){
				ok=false;
				break;
			}
		}
		if(ok){
			 cout<<"Yes\n";
			 return 0;
		}
	}
	cout<<"No\n";
	return 0;
}