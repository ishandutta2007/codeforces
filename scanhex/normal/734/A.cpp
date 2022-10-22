#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n; cin >> n;
	string s; cin >> s;
	int c1 = 0;
	for (auto& x : s)
		c1 += int(x == 'A');
	if (c1 == n - c1)
		cout << "Friendship" << endl;
	if (c1 < n - c1)
		cout << "Danik" << endl;
	if (c1 > n - c1)
		cout << "Anton" << endl;
}