#include <map>
#include <iostream>
using namespace std;
int Q, tp, p, l; map<int, int> d[27];
int main() {
	ios::sync_with_stdio(false);
	cin >> Q;
	while (Q--) {
		cin >> tp >> p;
		if (tp <= 2) for (int i = 0; i < 27; i++) d[i][p >> i] += (tp == 1 ? 1 : -1);
		else {
			cin >> l;
			int ret = 0;
			for (int i = 26; i >= 0; i--) {
				if (l & (1 << i)) ret += d[i][((p ^ l) >> i) ^ 1];
			}
			cout << ret << endl;
		}
	}
	return 0;
}