#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int A[101] = {0, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 0, 5, 2, 2, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 2, 7, 4, 0, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 4, 5, 5, 2, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 3, 7, 4, 8, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 4, 5, 5, 9, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 3, 7};
int B[MAXN];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 101; i++) B[i] = A[i];
	for (int i = 101; i < MAXN; i++) B[i] = B[i - 34];	
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		if (count(all(s), 'R') > count(all(s), 'B')) cout << "Alice" << endl;
		else if (count(all(s), 'R') < count(all(s), 'B')) cout << "Bob" << endl;
		else {
			int ans = 0, lst = -1, cnt = 0;
			for (int i = 1; i < n; i++) {
				int x = (s[i] == s[i - 1] ? 0 : 1);
				if (x != lst) {
					if (lst == 1) ans ^= B[cnt];
					cnt = 0;
				}

				lst = x;
				cnt++;
			}

			if (lst == 1) ans ^= B[cnt];
			cout << (ans ? "Alice" : "Bob") << endl;
		}
	}
	return 0;
}