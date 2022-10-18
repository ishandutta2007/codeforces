#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;

	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		bool flag = false;
		for (int j = 0; j < i; j++) {
			if (v[j] == v[i]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		cout << endl;
	}

	exit(0);
}