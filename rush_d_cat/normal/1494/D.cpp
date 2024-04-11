#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500 + 10;
int a[N][N];
int ans[N<<2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j]; 
		}
		ans[i]=a[i][i];
	}

	vector<int> v;
	for(int i=1;i<=n;i++) v.push_back(i);
	queue< vector<int> > q;
	q.push(v);
	int cur=n;

	map< vector<int>,int > mp; mp[v] = ++cur;

	vector< pair<int,int> > edges;	
	while(q.size()){
		vector<int> v = q.front(); q.pop();
		int mx=0;
		for(auto y:v) mx=max(mx,a[v[0]][y]);
		vector<bool> vis(v.size(),false);
		ans[mp[v]]=mx;

		for(int i=0;i<v.size();i++){
			if(vis[i]) continue;
			vector<int> tmp; tmp.push_back(v[i]);
			vis[i]=true;
			for(int j=i+1;j<v.size();j++){
				if(a[v[i]][v[j]] != mx) {
					tmp.push_back(v[j]); vis[j]=true;
				}
			}
			mp[tmp] = ((tmp.size()==1)?tmp[0]:++cur); 
			int now=mp[v];
			edges.push_back(make_pair(now,mp[tmp])); if(tmp.size()>1)q.push(tmp);
		}
	}
	cout<<cur<<endl;
	for(int i=1;i<=cur;i++)cout<<ans[i]<<(" \n"[i==cur]);
	cout<<n+1<<endl;
	for(auto e:edges) {
		if(ans[e.first]>ans[e.second])swap(e.first,e.second);
		cout<<e.first<<" "<<e.second<<endl;
	}
}