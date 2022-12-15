#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 2e5 + 7;
const int kCountLetters = 26;

int prefix[kMaxN][kCountLetters];

int count_letter(int l, int r, int letter){
	if(l == 0)
		return prefix[r][letter];
	return prefix[r][letter] - prefix[l - 1][letter];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int n = s.size();
	for(int j = 0; j < kCountLetters; ++j){
		int prev = 0;
		for(int i = 0; i < n; ++i){
			if(s[i] - 'a' == j)
				++prev;
			prefix[i][j] = prev;
		}
	}

	int q;
	cin >> q;

	for(int i = 0; i < q; ++i){
		int l, r;
		cin >> l >> r;
		--l;
		--r;

		if(l == r){
			cout << "Yes\n";
			continue;
		}

		bool ok = false;
		int cnt = 0;
		for(int j = 0; j < kCountLetters; ++j){
			if(count_letter(l, r, j)){
				++cnt;
			}
		}

		if(s[l] != s[r] || cnt >= 3)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}