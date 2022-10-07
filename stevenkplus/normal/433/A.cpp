#include <cstdio>

bool go() {
int n, a, b;
scanf("%d", &n);
a = b = 0;
for(int i = 0; i < n; ++i) {
int nxt;
scanf("%d", &nxt);
if (nxt == 100) ++a;
else ++b;
}
if (b % 2 == 0) {
return a % 2 == 0;
} else {
return a % 2 == 0 && a >= 2;
}
}

int main() {
if (go()) printf("YES\n");
else printf("NO\n");
}