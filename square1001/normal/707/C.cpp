#include <iostream>
using namespace std;
typedef long long ll;
ll n;
int main() {
	cin >> n;
	if (n <= 2) cout << -1 << endl;
	else if (n % 2 == 1) cout << (n * n - 1) / 2 << ' ' << (n * n + 1) / 2 << endl;
	else cout << (n * n - 4) / 4 << ' ' << (n * n + 4) / 4 << endl;
	return 0;
}