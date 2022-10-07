#include <cstdio>

int N;

int main() {
scanf("%d", &N);
int a, b;
int run = 0;
int ans = 0;
for(int i = 0; i < N; ++i) {
int nxt;
scanf("%d", &nxt);
if (run >= 2 && a + b != nxt) run = 1;
++run;
a = b;
b = nxt;
if (run > ans) ans = run;
}
printf("%d\n", ans);
return 0;
}