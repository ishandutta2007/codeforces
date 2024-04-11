#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e7 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

int SPF[MAXN], n, a;

inline int Ans(int n) {
	int L = 1, ans = 1;
	while (n > 1) {
		int s = SPF[n];
		n /= s;
		if (L == s) L = 1, ans /= s;
		else L = s, ans *= s;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	SPF[1] = 1;
	for (int i = 2; i < MAXN; i++) SPF[i] = i;
	for (int i = 2; i < MAXN; i++) 
		if (SPF[i] == i) 
			for (int j = 2 * i; j < MAXN; j += i)
				if (SPF[j] == j) 
					SPF[j] = i;
	cin >> a >> n;
	ll ans = 0;	
	for (int i = a; i < a + n; i++) ans += Ans(i);
	cout << ans << endl;
	return 0;
}