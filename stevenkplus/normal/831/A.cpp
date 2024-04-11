#include <cstdio>
bool solve() {
int N;
scanf("%d", &N);
int up = 0;
int prev = 0;
for(int i = 0; i < N; ++i) {
int x;
scanf("%d", &x);
if (up == 0) {
if (x <= prev) up++;
}
if (up == 1) {
if (x != prev) up++;
}
if (up == 2) {
if (x >= prev) return false;
}
prev = x;
}
return true;
}
int main() {
if (solve()) {
printf("YES\n");
} else {
printf("NO\n");
}
}