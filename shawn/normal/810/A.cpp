#include <cstdio>

using namespace std;

int rd() {
	int x = 0; char c = getchar(); 
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

int n, k, tot, sum;
int main() {
	n = rd(), k = rd();
	for (int i = 1; i <= n; i ++) {
		int x = rd();
		sum += x;
		tot ++;
	}
	while (1) {
		int ave = (double) sum / tot + .5;
		if (ave >= k) break;
		tot ++;
		sum += k;
	}
	printf("%d", tot - n);
	return 0;
}