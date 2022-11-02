#include <bits/stdc++.h>
using namespace std;
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define N 2005
#define M 6105

char s[N], t[N], ss[N];
int a[30], b[30], q[M], qs, n;

void shift(int x) {
	q[qs ++] = x;
    reverse(s + n - x + 1, s + n + 1);
    f1(i, n - x + 1, n) ss[i - n + x] = s[i];
    f1(i, x + 1, n) ss[i] = s[i-x];
    f1(i, 1, n) s[i] = ss[i];
    s[n+1] = 0;
    return;
}

int main() {
    scanf("%d", &n);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	f1(i, 1, n) a[s[i] - 'a'] ++, b[t[i] - 'a'] ++;
    f0(i, 0, 26) if (a[i] != b[i]) {
        puts("-1");
        return 0;
    }
    f0(i, 0, n) {
		shift(n);
        f1(j, 1, n - i) if (s[j] == t[n-i]) {
            shift(n - j);
            break;
        }
        shift(1);
    }
    printf("%d\n", qs);
    f0(i, 0, qs) printf("%d ", q[i]);
	return 0;
}