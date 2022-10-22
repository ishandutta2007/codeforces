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
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int r, c;
	cin >> r >> c;
	if (r + c == 2) {
		cout << "0\n";
		return 0;
	}
	if (c == 1) {
		for (int j = 1; j <= r; j++) {
			cout << j + 1 << "\n";
		}
		return 0;
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << i * (j + r) << " ";
		}
		cout << "\n";
	}

}