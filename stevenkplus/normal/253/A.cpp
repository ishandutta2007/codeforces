#include <cstdio>
#include <iostream>

using namespace std;

int B, G;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> B >> G;
	bool boy = B > G;
	int N = B + G;
	for(int i = 0; i < N; ++i) {
		if (G == 0 || boy && B > 0) {
			printf("B");
			B--;
			boy = !boy;
		} else {
			G--;
			printf("G");
			boy = true;
		}
	}
	printf("\n");
	return 0;
}