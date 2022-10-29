#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;cin >> n;
	string s; cin >> s;
	int curr = 0;
	vector<int> v;
	for(char c : s){
		if(c == 'B'){
			curr++;
		}
		else{
			if(curr){
				v.push_back(curr);
				curr = 0;
			}
		}
	}
	if(curr){
		v.push_back(curr);
	}
	cout << v.size() << "\n";
	for(auto c : v){
		cout << c << " ";
	}
	return;		
}

int main(){
	solve();
	return 0;	
}