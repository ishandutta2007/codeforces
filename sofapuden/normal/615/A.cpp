#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m; cin >> n >> m;
	set<int> s;
	for(int i = 0; i < n; ++i){
		int am; cin >> am;
		for(int j = 0,tmp; j < am; ++j){
			cin >> tmp;
			s.insert(tmp);
		}
	}
	cout << ((int)size(s) == m ? "YES" : "NO") << "\n";
			
}