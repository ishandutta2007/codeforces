#include <bits/stdc++.h>

using namespace std;

vector<string> res;

bool cmp(string lvalue, string rvalue){
	if(lvalue.size() != rvalue.size()){
		return lvalue.size() < rvalue.size();
	}

	for(int i = 0; i < lvalue.size(); i++){
		if(lvalue[i] != rvalue[i]){
			return lvalue[i] < rvalue[i];
		}
	}

	return false;
}

void solve(){
	int n;
	string s;

	cin >> n >> s;

	string curr = "";
	curr += s[0];

	string t = "";	

	for(int i = 1; i < s.size(); i++)
		t += s[i];

	res.clear();
	res.push_back(curr);

	if(!cmp(curr, t)){
		cout << "NO\n";

		return ;
	}

	cout << "YES\n";

	cout << "2\n";

	cout << curr << " " << t;
	cout << "\n";

	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int q;

	cin >> q;

	while(q--){
		solve();
	}

	return 0;
}