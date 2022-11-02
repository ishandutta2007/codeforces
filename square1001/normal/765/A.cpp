#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n; string s, t[109];
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> t[i];
	if (n % 2 == 1) cout << "contest" << endl;
	else cout << "home" << endl;
	return 0;
}