#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
//#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN] = {0};

int main() {
	set<ll> st;
	set<ll> st2;
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++) st.insert(i), st2.insert(i);
	while (st.size() > 1) {
		ll i = *st.begin(), j = *st.rbegin();
		cout << "? " << i << sep << j << endl;
		ll ans1, ans2;
		cin >> ans1;
		cout << "? " << j << sep << i << endl;
		cin >> ans2;
		if (ans2 > ans1) {
			A[j] = ans2;
			st2.erase(ans2);
			st.erase(j);
		} else {
			A[i] = ans1;
			st2.erase(ans1);
			st.erase(i);
		}
	}

	for (int i = 1; i <= n; i++)
		if (A[i] == 0) 
			A[i] = *st2.begin();
	cout << "! ";
	for (int i = 1; i <= n; i++) cout << A[i] << sep;
	cout << endl;
	return 0;
}