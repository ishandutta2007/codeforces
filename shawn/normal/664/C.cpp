#include <bits/stdc++.h>

using namespace std;

int read() {
	int a = 0 , f = 1 , c = getchar();
	while (c > '9' && c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') a = a * 10 + c - 48 , c = getchar();
	return a * f;
}

void write(int a) {
	if (a < 0) putchar('-'), write(-a);
	if (a >= 10) write(a / 10);
	putchar(a % 10 + 48);
}

string a;

int main() {
	for (int t = read(); t; t --) {
		cin >> a;
		a = a.substr(4);
		int L = a.length();
		if (L == 1) {
			if (a[0] >= '0' && a[0] <= '8') cout << "199" + a << endl;
			else cout << "1989" << endl;
		}
		else if (L == 2) {
			if (a == "99") cout << "1999" << endl;
			else cout << "20" + a << endl;
		}
		else if (L == 3) {
			if (a >= "000" && a <= "098") cout << "3" + a << endl;
			else cout << "2" + a << endl;
		}
		else if (L == 4) {
			if (a >= "3099" && a <= "9999") cout << a << endl;
			else cout << "1" + a << endl;
		}
		else if (L == 5) {
			if (a >= "13099" && a <= "99999") cout << a << endl;
			else cout << "1" + a << endl;
		}
		else if (L == 6) {
			if (a >= "113099" && a <= "999999") cout << a << endl;
			else cout << "1" + a << endl;
		}
		else if (L == 7) {
			if (a >= "1113099" && a <= "9999999") cout << a << endl;
			else cout << "1" + a << endl;
		}
		else if (L == 8) {
			if (a >= "11113099" && a <= "99999999") cout << a << endl;
			else cout << "1" + a << endl;
		}
		else if (L == 9) {
			if (a >= "111113099" && a <= "999999999") cout << a << endl;
			else cout << "1" + a << endl;
		}
	}
}