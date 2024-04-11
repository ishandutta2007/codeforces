#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

int main() {
	ios :: sync_with_stdio(0);
	int k; cin >> k;
	string s;
	for(char c = 'a'; c <= 'z'; c ++) {
		int i = 0;
		while(i * (i + 1) / 2 <= k)
			i ++;
		k -= i * (i - 1) / 2;
		while(i --) s += c;
	}
	cout << s << '\n';
	return 0;
}