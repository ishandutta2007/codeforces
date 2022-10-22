#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int Q = 31;
const int P1 = 1e9 + 7, P2 = 1e9 + 9;

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vector <char> prefmin(n, 'z');
	prefmin[0] = s[0];
	for (int i = 1; i < n; i++) {
		prefmin[i] = min(prefmin[i - 1], s[i]);
	}
	cout << "Mike\n";
	for (int i = 1; i < n; i++) {
		if (prefmin[i - 1] < s[i]) {
			cout << "Ann\n";
		} else {
			cout << "Mike\n";
		}
	}

}