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

ll A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		bool flag = true;
		for (int i = 1; i <= n; i++) cin >> A[i];
	
		for (int i = 1; i < n; i++) {
			A[i + 1] += A[i];
			flag &= (A[i] >= 0);
		}

		flag &= (A[n] == 0);
		int lst = n;
		while (A[lst] == 0 && lst > 0) lst--;
		for (int i = 1; i <= lst; i++)
			flag &= (A[i] > 0);
		cout << (flag ? "Yes" : "No") << endl;
	}
	return 0;
}