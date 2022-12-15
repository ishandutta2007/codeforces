#include <bits/stdc++.h>

using namespace std;

int cnt[256];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	string s;

	cin >> s;

	for(char c: s){
		++cnt[c];
	}

	for(int i = 0; i < cnt['o'] - cnt['z']; ++i){
		cout << "1 ";
	}
	for(int i = 0; i < cnt['z']; ++i){
		cout << "0 ";
	}
	cout << "\n";
	return 0;
}