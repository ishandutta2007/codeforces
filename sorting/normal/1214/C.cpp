#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	string s;

	cin >> s;

	int curr = 0, cnt = 0;
	for(char c: s){
		curr += (c == '(') ? 1 : -1;

		if(curr < -1){
			cout << "NO\n";
			return 0;
		}
	}

	if(curr != 0){
		cout << "NO\n";

		return 0;
	}
	
	cout << "YES\n";

	return 0;
}