#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 1001000;

typedef long long ll;
char str[MAXN];
char h[] = "heavy";
char m[] = "metal";

int main() {
	scanf("%s", str);
	int left = 0;

	int a = 0;
	int b = 0;

	ll ans = 0;
	for(int i = 0; str[i]; ++i) {
		if (str[i] != h[a]) a = 0;
		if (str[i] == h[a]) ++a;

		if (str[i] != m[b]) b = 0;
		if (str[i] == m[b]) ++b;

		if (b == 5) {
			ans += left;
		}
		if (a == 5) {
			++left;
		}
	}

	cout << ans << endl;
	return 0;
}