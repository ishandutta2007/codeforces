#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const string VOW = "aeiou";

int main() {
	string s;
	cin >> s;
	int ret = 0;

	rep(i, s.size()) {
		if (isalpha(s[i])) {
			int p = -1;
			rep(j, VOW.size()) if (s[i] == VOW[j]) {
				p = j;
			}
			if (p != -1) {
				++ret;
			}
		} else {
			int t = s[i] - '0';
			if (t & 1) {
				++ret;
			}
		}
	}

	cout << ret << endl;

	return 0;
}