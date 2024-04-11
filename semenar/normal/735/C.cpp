#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

#define INF ((long long)1e18)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	vector<long long> fib;
	fib.push_back(1);
	fib.push_back(2);
	while (fib[fib.size() - 1] + fib[fib.size() - 2] <= INF) {
		fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
	}
	int max_games;
	for (int i = 0; i < fib.size(); i++) {
		if (n >= fib[i]) {
			max_games = i;
		}
	}
	cout << max_games;
	return 0;
}