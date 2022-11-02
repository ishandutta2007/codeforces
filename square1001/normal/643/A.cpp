#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, a[5009], c[5009], d[5009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i]--;
	for (int i = 0; i < n; i++) {
		fill(c, c + n, 0);
		int ptr = 0;
		for (int j = i; j < n; j++) {
			c[a[j]]++;
			if (c[a[j]] > c[ptr] || (c[a[j]] == c[ptr] && ptr > a[j])) ptr = a[j];
			d[ptr]++;
		}
	}
	for (int i = 0; i < n; i++) printf("%d ", d[i]);
	return 0;
}