#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a;
	cin >> a;
	string ba = a;
	reverse(ba.begin(), ba.end());
	cout << a << ba << endl;
	cin >> a;
}