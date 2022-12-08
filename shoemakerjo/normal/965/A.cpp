#include <bits/stdc++.h>

using namespace std;

int main() {
	int k, n, s, p;
	cin >> k >> n >> s >> p;
	int numsheets = (n)/s;
	if ((k*n)%s != 0) numsheets++;
	numsheets *= k;
	int ans = numsheets/p;
	if (numsheets%p != 0) ans++;
	cout << ans << endl;
	cin >> n;
}