#include<bits/stdc++.h>
using namespace std;

int main() {
	int T, a, b;
	cin >> T;
	while(T --) {
		cin >> a >> b;
		if((a + b) % 2 == 1) puts("-1");
		else if (a != b) puts("2");
		else if (!a) puts("0");
		else puts("1");
	}
	return 0;
}