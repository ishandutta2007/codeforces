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
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int odd = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x % 2) {
			odd++;
		}
	}
	cout << min(odd, n - odd) << "\n";
}