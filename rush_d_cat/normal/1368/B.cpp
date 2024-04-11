#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
typedef long long LL;
LL k;
string s = "codeforces";
LL c[10] = {0};
void output() {
	for (int i = 0; i < 10; i ++) {
		for (int j = 0; j < c[i]; j ++) printf("%c", s[i]);
	}
}
int main() {
	scanf("%lld", &k);
	for (int i = 0; i < 10; i ++) c[i] = 1;

	if (k == 1) {
		output(); return 0;
	}

	while (1) {
		for (int i = 0; i < 10; i ++) {
			c[i] ++;
			LL M = 1;
			for (int j = 0; j < 10; j ++) M *= c[j];
			if (M >= k) {
				output(); return 0;
			}
		}
	}
}