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
	map <char, int> cnt;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		cnt[c]++;
	}
	int zero = 0, one = 0;
	while (cnt['z']) {
		cnt['z']--, cnt['e']--, cnt['r']--, cnt['o']--;
		zero++;
	}
	while (cnt['o']) {
		cnt['o']--;
		one++;
	}
	for (int i = 0; i < one; i++) {
		cout << "1 ";
	}
	for (int i = 0; i < zero; i++) {
		cout << "0 ";
	}
	cout << "\n";
}