#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >>t ;
	while(t--){
		int n;
		cin >> n;
		vector<int>a(n);
		for(auto&x:a)cin >> x;
		set<int>st;
		for(int i = 0; i < n; ++i){
			st.insert(((i + a[i]) % n + n) % n);
		}
		if (st.size() != n)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}