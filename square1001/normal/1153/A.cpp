#include <iostream>
using namespace std;
const int inf = 1012345678;
int main() {
	int N, T;
	cin >> N >> T;
	int opt = inf, pos = -1;
	for (int i = 0; i < N; ++i) {
		int S, D;
		cin >> S >> D;
		int nxt = S;
		if (nxt < T) nxt = (T - S + D - 1) / D * D + S;
		if (nxt < opt) {
			opt = nxt;
			pos = i;
		}
	}
	cout << pos + 1 << endl;
	return 0;
}