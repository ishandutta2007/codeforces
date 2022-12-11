#include <cstdio>
#include <string>
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
typedef long long ll;
const int N = 1e6 + 34;
char ss[N];
std::string s;
int z[N], l, r, n, ans = -1, mx;
int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);
    scanf("%s", ss);
    s = ss;
    n = s.length();
    s += "@";
    for (int i = 1; i < n; i++) {
    	z[i] = min(z[i - l], max(0, r - i));
    	while (s[z[i]] == s[i + z[i]]) 
    		z[i]++;
    	if (i + z[i] > r) {
    		r = i + z[i];
    		l = i;
    	}
    	if (i + z[i] == n)
    		mx = max(mx, z[i] - 1);
    	else
    		mx = max(mx, z[i]);
    }
    for (int i = 1; i <= min(n - 2, mx); i++) {
    	if (z[n - i] == i)
    		ans = i;
    }
    if (ans == -1)
    	printf("Just a legend\n");
    else {
    	for (int i = 0; i < ans; i++)
    		printf("%c", s[i]);
    }
}