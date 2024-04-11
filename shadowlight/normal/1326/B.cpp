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
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector <int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	int x = 0;

	for (int i = 0; i < n; i++) {
		cout << b[i] + x << " ";
		x = max(x, b[i] + x);
	}
	cout << "\n";

}