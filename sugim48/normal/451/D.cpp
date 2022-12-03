#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

char s[100001];
ll a0, a1, b0, b1, e, o;

int main() {
	scanf("%s", s);
	for (int i = 0; s[i] != '\0'; i++) {
		if (i % 2 == 0) {
			if (s[i] == 'a') {
				a0++;
				e += a1;
				o += a0;
			}
			else {
				b0++;
				e += b1;
				o += b0;
			}
		}
		else {
			if (s[i] == 'a') {
				a1++;
				e += a0;
				o += a1;
			}
			else {
				b1++;
				e += b0;
				o += b1;
			}
		}
	}
	printf("%I64d %I64d\n", e, o);
}