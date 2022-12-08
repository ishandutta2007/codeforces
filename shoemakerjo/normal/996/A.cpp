#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	//1, 5, 20, 100
	int ans = 0;
	ans += n/100;
	n %= 100;
	ans += n/20;
	n %= 20;
	ans += n/10;
	n %= 10;
	ans += n/5;
	n %= 5;
	ans += n;
	cout << ans << endl;
}