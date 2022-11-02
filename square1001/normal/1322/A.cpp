#include <string>
#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N; string S;
	cin >> N >> S;
	int depth = 0, cost = 0;
	for (int i = 0; i < N; ++i) {
		if (S[i] == '(') ++depth;
		else --depth;
		if (depth < 0 && S[i] == ')') {
			cost += 2;
		}
	}
	if (depth != 0) {
		cout << -1 << endl;
	}
	else {
		cout << cost << endl;
	}
	return 0;
}