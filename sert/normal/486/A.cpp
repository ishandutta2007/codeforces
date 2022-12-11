#include <cstdio>
int main() {
long long n;
scanf("%I64d", &n);
printf("%I64d\n", n / 2 - n * (n % 2));
return 0;
}