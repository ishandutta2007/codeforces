#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	char cf[11] = "codeforces";
	long long k, ptr = 0;
	scanf("%lld", &k);
	long long ans = 1, arr[10];
	fill_n(arr, 10, 1);
	while (ans < k) {
		ans /= arr[ptr];
		++arr[ptr];
		ans *= arr[ptr];
		ptr = (ptr + 1) % 10;
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < arr[i]; ++j) printf("%c", cf[i]);
	}
	return 0;
}