#include <bits/stdc++.h>

//http://codeforces.com/contest/791/problem/A



using namespace std;


typedef long long LL;
typedef pair<LL,LL> pp;


int main() {
	LL a, b, y = 0;

	cin >> a >> b;
	while (a <= b) {
		y++;
		a *= 3;
		b *= 2;
	}
	cout << y << endl;
}