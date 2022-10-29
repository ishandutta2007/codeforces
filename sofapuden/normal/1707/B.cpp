#include<bits/stdc++.h>

using namespace std;
void solve(){
	int n; cin >> n;
	vector<int> v(n); for(auto &x : v)cin >> x;
	map<int,int> m;
	for(int i = 0; i < n; ++i)m[v[i]]++;
	for(int i = 0; i < n-1; ++i){
		map<int,int> ne;
		for(auto it = m.begin(); it != m.end(); ++it){
			ne[0]+=it->second-1;
			if(next(it) == m.end())break;
			ne[next(it)->first - it->first]++;
		}
		swap(ne,m);
		if(!m[0])m.erase(0);
	}
	cout << m.begin()->first << '\n';
}

int main(){
	int t; cin >> t;
	while(t--)solve();

}