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

int n;
string s;
bool ok[200010];

int main() {
	cin >> n >> s;
	int i = 0;
	while (i < n) {
		if (s[i] == '<') {
			ok[i] = 1;
			++i;
		} else break;
	}

	i = n - 1;
	while (i >= 0) {
		if (s[i] == '>') {
			ok[i] = 1;
			--i;
		} else break;	
	}

	int ans = 0;
	rep(i, n) ans += ok[i];
	cout << ans << endl;

	return 0;
}