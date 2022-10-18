#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit | cin.eofbit | cin.badbit);
	int N, T;
	string str;
	cin >> N >> T >> str;
	size_t dot = str.find('.');
	for (size_t i = dot+1; i < str.size(); i++) {
		if (str[i] >= '5') {
			str.erase(str.begin() + i, str.end());
			--T;
			while (T) {
				if (str.back() == '4') {
					str.pop_back();
					--T;
					continue;
				}
				else break;
			}
			if (str.back() == '.') {
				str.pop_back();
				bool done = false;
				for (int j = sz(str)-1; j >= 0; --j) {
					if (str[j] != '9') {
						str[j]++;
						done = true;
						break;
					}
					else {
						str[j] = '0';
					}
				}
				if (!done) str = '1' + str;
			}
			else {
				str.back() += 1;
			}
			break;
		}
	}
	cout << str << endl;
	exit(0);
}