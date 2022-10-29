#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> ou;
		string s; cin >> s;
		int l = 0, r = n-1;
		while(l <= r){
			while(l <= r){
				if(s[l++] == '1'){ou.push_back(l); break;}
			}
			while(l <= r){
				if(s[r--] == '0'){ou.push_back(r+2); break;}
			}
		}
		sort(ou.begin(),ou.end());
		if(ou.size() == 0 || ou.size() == 1){
			cout << "0\n";
			continue;
		}
		cout << "1\n";
		cout << ou.size() << ' ';
		for(auto x : ou)cout << x << ' ';
		cout << '\n';
	}
}