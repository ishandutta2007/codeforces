#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;

	cin >> s;

	int mn = 256;
	bool win = false;

	for(int i = 0; i < (int)s.size(); ++i){
		if(s[i] <= mn){
			mn = s[i];
			cout << "Mike" << "\n";
		}
		else{
			cout << "Ann" << "\n";
		}
	}

	return 0;
}