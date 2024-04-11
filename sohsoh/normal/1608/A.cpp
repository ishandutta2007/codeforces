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

const ll MAXN = 1e5 + 10;

int A[MAXN];

inline bool prime(int n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<int> p_vec;
	for (int i = 2; i < MAXN; i++)
		if (prime(i))
			p_vec.push_back(i);


	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;	
		for (int i = 0; i < n; i++)
			cout << p_vec[i] << sep;
		cout << endl;
	}
	return 0;
}