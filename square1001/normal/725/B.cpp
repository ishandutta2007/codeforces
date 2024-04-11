#include <string>
#include <iostream>
using namespace std;
string s;
int main() {
	cin >> s;
	char c = s.back(); s.pop_back();
	long long n = stoll(s); n--;
	int e = 0;
	if (c == 'e') e = 1;
	if (c == 'd') e = 2;
	if (c == 'a') e = 3;
	if (c == 'b') e = 4;
	if (c == 'c') e = 5;
	n = n / 4 * 16 + n % 2 * 7;
	cout << n + e + 1 << endl;
	return 0;
}