#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
int n, a[100009], c[55]; char s[100009];
int main() {
	scanf("%d%s", &n, s);
	ll allbit = 0;
	for (int i = 0; i < n; i++) {
		if ('A' <= s[i] && s[i] <= 'Z') a[i] = s[i] - 'A';
		else a[i] = s[i] - 'a' + 26;
		allbit |= 1LL << a[i];
	}
	int r = 0, ret = 999999999; ll bit = 0;
	for (int i = 0; i < n; i++) {
		while (r < n && bit != allbit) {
			c[a[r]]++;
			bit |= 1LL << a[r++];
		}
		if (bit != allbit) break;
		ret = min(ret, r - i);
		c[a[i]]--;
		if (c[a[i]] == 0) bit -= 1LL << a[i];
	}
	printf("%d\n", ret);
	return 0;
}