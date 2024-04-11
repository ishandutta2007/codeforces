#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N];
int aAb, aAc, bAc, aXb, aXc, bXc;

int main() {
	cin >> n;
	cout << "AND 1 2\n", cin >> aAb, cout.flush();
	cout << "AND 1 3\n", cin >> aAc, cout.flush();
	cout << "AND 2 3\n", cin >> bAc, cout.flush();
	cout << "XOR 1 2\n", cin >> aXb, cout.flush();
	cout << "XOR 1 3\n", cin >> aXc, cout.flush();
	bXc = aXb ^ aXc;
	int ab = 2 * aAb + aXb;
	int ac = 2 * aAc + aXc;
	int bc = 2 * bAc + bXc;
	a[1] = (ab + ac - bc) / 2;
	a[2] = (ab + bc - ac) / 2;
	a[3] = (ac + bc - ab) / 2;
	for(int i = 4; i <= n; i++) {
		int x;
		cout << "XOR 1 " << i << endl, cin >> x, cout.flush();
		a[i] = a[1] ^ x;
	}
	cout << "! ";
	for(int i = 1; i <= n; i++) cout << a[i] << " ";
	return 0;
}