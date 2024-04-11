#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

ll hs(string s) {
	ll r = 0;
	for(int i = 0; i < s.size(); i ++)
		r = r * 11 + s[i] - '0' + 1;
	return r;
}

const int N = 1e5L + 11;
string s[N];

int main() {
	ios :: sync_with_stdio(0);
	
	int n; cin >> n;
	map <ll, int> mp;
	for(int i = 0; i < n; i ++) {
		cin >> s[i];
		for(int j = 0; j < 9; j ++)
			for(int k = j; k < 9; k ++)
				mp[hs(s[i].substr(j, k - j + 1))] ++;
	}
	
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < 9; j ++)
			for(int k = j; k < 9; k ++)
				mp[hs(s[i].substr(j, k - j + 1))] --;
		
		for(int j = 1; j <= 9; j ++)
			for(int k = 0; k + j <= 9; k ++) {
				auto it = mp.find(hs(s[i].substr(k, j)));
				if(it == mp.end() || it -> second == 0) {
					cout << s[i].substr(k, j) << '\n';
					goto end;
				}
			}
		end: ;
		
		for(int j = 0; j < 9; j ++)
			for(int k = j; k < 9; k ++)
				mp[hs(s[i].substr(j, k - j + 1))] ++;
	}
	
	return 0;
}