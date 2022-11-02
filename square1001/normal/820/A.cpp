#include <bits/stdc++.h>
using namespace std;
int c, v0, v1, a, l;
int main() {
	cin >> c >> v0 >> v1 >> a >> l;
	int sum = 0;
	for(int i = 0; ; i++) {
		sum += min(v1, v0 + i * a);
		if(i >= 1) sum -= l;
		if(sum >= c) {
			cout << i + 1 << endl;
			break;
		}
	}
	return 0;
}