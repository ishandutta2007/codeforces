#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{

	vector<int> v(3);
	for (int i = 0; i < 3; i++) {
		cin >> v[i];
	}
	int t = 0;
	for (int s = 100; s >= 1; s--) {
		if (v[0] >= s && v[1] >= s+1 && v[2] >= s+2) {
			t = s+s+1+s+2;
			break;
		}
	}
	cout << t << endl;
	exit(0);
}