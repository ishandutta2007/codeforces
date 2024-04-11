#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

const int N=500500;
vector<int>g[N];
int t[N];

int mex(vector<int>& v){
	vector<bool>kek(v.size()+3);
	for(int x:v)
		if (x < kek.size())kek[x]=true;
	int i=1;
	while(kek[i])++i;
	return i;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >>n >> m;
	for(int i=0;i<m;++i){
		int a,b;
		cin >> a >> b;
		--a,--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=0;i<n;++i)
		cin >> t[i];
	vector<int>ord(n);
	iota(ord.begin(),ord.end(),0);
	sort(ord.begin(),ord.end(),[&](int a,int b){
			 return t[a] < t[b];
			});
	for(auto x:ord){
		vector<int>v;
		for(int y:g[x])
			v.push_back(t[y]);
		if (mex(v) != t[x]) {
			 cout << -1 << '\n';
			 return 0;
		}
	}
	for(int x : ord)
		cout << x + 1 << ' ';;
	cout << '\n';

	return 0;
}