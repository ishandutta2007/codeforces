#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int N=300300;
vector<pair<int,int>>g[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		 int n,m;
		 cin>>n>>m;
		 for(int i=0;i<3*n;++i)g[i].clear();
		 for(int i=0;i<m;++i){
			  int a,b;
			  cin>>a>>b;
			  --a,--b;
			  g[a].emplace_back(b,i);
			  g[b].emplace_back(a,i);
		 }
		 vector<bool>used(3*n);
		 vector<int>a,b;
		 for(int i=0;i<3*n;++i){
			 if(used[i])continue;
			 bool ok=true;
			 for(auto [j,k]:g[i]){
				 if(used[j]){
					 continue;
				 }
				 ok=false;
				 a.push_back(k);
				 used[j]=true;
				 break;
			 }
			 if(ok)b.push_back(i);
			 used[i]=true;
		 }
		 if(a.size()>=n){
			 cout<<"Matching\n";
			 for(int i=0;i<n;++i)
				 cout<<a[i]+1<<' ';
			 cout<<'\n';
		 }
		 else{
			 cout<<"IndSet\n";
			 for(int i=0;i<n;++i)
				 cout<<b[i]+1<<' ';
			 cout<<'\n';
		 }
	}
	return 0;
}