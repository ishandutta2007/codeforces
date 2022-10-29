#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a, b;
		for(int i = 0; i < n; ++i){
			int x; cin >> x;
			if(x&1)a.push_back(x);
			else b.push_back(x);
		}
		vector<int> c = a, d = b;
		sort(c.begin(),c.end());
		sort(d.begin(),d.end());
		cout << (a == c && d == b ? "Yes\n" : "No\n");
	}
}