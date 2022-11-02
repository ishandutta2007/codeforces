#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, cnt[30];
typedef long long ll;

ll T;
char s[N];

int main() {
    scanf("%d %lld", &n, &T);
    scanf("%s", s);
    for (int i = 0; i < n - 2; i ++) cnt[s[i]-'a'] ++;
    T -= (1 << s[n-1]-'a');
    T += (1 << s[n-2]-'a');
    ll sum = 0;
    for (int i = 0; i < 26; i ++) sum += (1ll << i) * cnt[i];
    if (T > sum) return puts("No"), 0;
    T = sum - T;
    if (T & 1) return puts("No"), 0;
    T >>= 1;
    for (int i = 25; i >= 0; i --) {
		int c = 1 << i;
		while (cnt[i] --) {
			if (T < c) break;
			T -= c;
		}
    }
    if (T != 0) return puts("No"), 0;
    return puts("Yes");

    return 0;
}