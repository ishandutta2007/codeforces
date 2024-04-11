#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int b = n / 2, a = n - b;

	if (n % 2) {
		cout << 2 * ((a + 1) * (ll)(b + 1)) << "\n";
	} else {
		cout << (a + 1) * (ll)(b + 1) << "\n";
	}
}