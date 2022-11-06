#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		if (i % 2) cout << "I love ";
		else cout << "I hate ";

		if (i < n - 1) cout << "that ";
	}
	cout << "it";
	return 0;
}