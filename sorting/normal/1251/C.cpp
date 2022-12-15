#include <bits/stdc++.h>

using namespace std;

vector<char> v1, v2;
vector<char> nxt1, nxt2;

void solve(){
	string s;

	cin >> s;
	v1.clear();
	v2.clear();

	for(char c: s){
		if((int)c & 1){
			v1.push_back(c);
		}
		else{
			v2.push_back(c);
		}
	}

	/*nxt1.clear();
	nxt2.clear();

	int pr = 0;
	for(int i = 1; i < (int)v1.size(); ++i){
		if(v1[i] != v1[i - 1]){
			for(int j = pr; j < i; ++j){
				nxt1.push_back(v1[i]);
			}
			pr = i;
		}
	}
	for(int j = pr; j < (int)v1.size(); ++j){
		nxt1.push_back('9' + 1);
	}

	pr = 0;
	for(int i = 1; i < (int)v2.size(); ++i){
		if(v2[i] != v2[i - 1]){
			for(int j = pr; j < i; ++j){
				nxt2.push_back(v2[i]);
			}
			pr = i;
		}
	}
	for(int j = pr; j < (int)v2.size(); ++j){
		nxt2.push_back('9' + 1);
	}*/

	string ret = "";

	int i = 0, j = 0;
	while(i != (int)v1.size() || j != v2.size()){
		if(i == (int)v1.size()){
			ret += v2[j];
			++j;
			continue;
		}
		if(j == (int)v2.size()){
			ret += v1[i];
			++i;
			continue;
		}
		if(v1[i] < v2[j]){
			ret += v1[i];
			++i;
			continue;
		}
		else{
			ret += v2[j];
			++j;
			continue;
		}
	}

	cout << ret << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	while(t--){
		solve();
	}
	return 0;
}