#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for(auto &x : v)cin >> x;
		int mx = 1;
		set<int> s;
		for(int i = 0; i < n; ++i){
			if(v[i] >= mx){
				cout << v[i] << " ";
				for(int j = mx; j < v[i]; ++j){
					s.insert(j);
				}
				mx = v[i]+1;
			}
			else {
				cout << *s.begin() << " ";
				s.erase(s.begin());
			}
		}
		cout << "\n";
		s.clear();
		mx = 1;
		for(int i = 0; i < n; ++i){
			if(v[i] >= mx){
				cout << v[i] << " ";
				for(int j = mx; j < v[i]; ++j){
					s.insert(j);
				}
				mx = v[i]+1;
			}
			else {
				cout << *prev(s.end()) << " ";
				s.erase(prev(s.end()));
			}
		}
		cout << "\n";


	}
}