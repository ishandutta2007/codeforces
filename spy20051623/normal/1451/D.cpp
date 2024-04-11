#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	long long t, d, k, i, j;
	cin >> t;
	while (t--) {
		cin >> d >> k;
		i = sqrt(1.0 * d * d / 2);
		i = i / k * k;
		j = sqrt(d * d - i * i);
		i = i / k;
		j = j / k;
		if ((i + j) % 2)
			cout << "Ashish" << endl;
		else
			cout << "Utkarsh" << endl;
	}
	return 0;
}