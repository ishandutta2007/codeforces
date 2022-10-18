#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

void f(int n) {
	if (n == 2) {
		cout << 2 << endl;
	}
	else {
		cout << n%2 << endl;
	}

}
int main()
{
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int n;
		cin >> n;
		f(n);
	}
	exit(0);
}