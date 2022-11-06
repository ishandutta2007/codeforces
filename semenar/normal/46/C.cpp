#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(X) X.begin(), X.end()
#define sz(X) ((int)X.size())
#define fst first
#define snd second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef vector<pll> vpll;
typedef vector<ld> vld;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vbb;

const int INT_INF = 2e9;

bool is_prime(int n) {
	for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;

	int hamsters = 0;
	for (auto ch : s) if (ch == 'H') hamsters++;

	int ans = INT_INF;

	for (int i = 0; i < n; i++) {
		int cur_ans = 0;
		for (int j = i; j < i + hamsters; j++) if (s[j % n] != 'H') cur_ans++;
		for (int j = i + hamsters; j < i + n; j++) if (s[j % n] != 'T') cur_ans++;
		ans = min(ans, cur_ans / 2);
	}

	cout << ans << endl;
}