#include <bits/stdc++.h>

using namespace std;

string vowels = "aeiou";

bool check(char c){
	for(char c2: vowels){
		if(c == c2){
			return true;
		}
	}

	return false;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s, t;

	cin >> s >> t;

	if(s.size() != t.size()){
		cout << "No\n";

		return 0;
	}

	for(int i = 0; i < s.size(); i++){
		if(check(s[i]) != check(t[i])){
			cout << "No\n";

			return 0;
		}
	}

	cout << "Yes\n";

	return 0;
}