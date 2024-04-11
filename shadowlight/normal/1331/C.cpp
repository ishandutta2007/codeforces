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

	int n;
	cin >> n;
	vector <int> a = {5, 0, 2, 3, 1, 4};
	int m = 0;
	for (int i = 0; i < 6; i++) {
		m = 2 * m;
		if ((1 << a[i]) & n) {
			m++;
		}
	}
	cout << m << "\n";
}