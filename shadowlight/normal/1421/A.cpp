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

	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		int x = 0;
		for (int j = 0; j < 30; ++j) {
			if (a & (1 << j) && b & (1 << j)) {
				x += 1 << j;
			}
		}
		cout << (a ^ x) + (b ^ x) << "\n";
	}

}