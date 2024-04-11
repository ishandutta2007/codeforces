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
	freopen("I_input.txt", "r", stdin);
	//freopen("I_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	if (n == 1 && k == 1) {
		s = "0";
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (cnt == k) break;
		if (!i && s[i] > '1') {
			s[i] = '1';
			cnt++;
		}
		if (i && s[i] > '0') {
			s[i] = '0';
			cnt++;
		}
	}
	cout << s;

}