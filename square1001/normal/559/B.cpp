#include <string>
#include <iostream>
using namespace std;
string calc(string s) {
	int n = s.size();
	if (n % 2 == 1) return s;
	string sa = calc(s.substr(0, n / 2));
	string sb = calc(s.substr(n / 2));
	return (sa < sb ? sa + sb : sb + sa);
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	string sa; cin >> sa; sa = calc(sa);
	string sb; cin >> sb; sb = calc(sb);
	cout << (sa == sb ? "YES\n" : "NO\n");
	return 0;
}