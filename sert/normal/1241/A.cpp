#include<cstdio>
int main() {
int t, x;
scanf("%d", &t);
while (t --> 0) {
scanf("%d", &x);
printf("%d\n", (x < 4 ? 4 - x : x % 2));
}
}