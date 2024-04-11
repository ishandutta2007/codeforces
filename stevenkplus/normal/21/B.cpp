#include <cstdio>

using namespace std;

int gcd(int a, int b) {
if (b == 0) return a;
return gcd(b, a % b);
}

int abs(int x) {
if (x < 0) return -x;
return x;
}

int a1,b1,c1;
int a2,b2,c2;
int main() {
scanf("%d %d %d", &a1, &b1, &c1);
scanf("%d %d %d", &a2, &b2, &c2);
if (a1 < 0) {
a1 *= -1;
b1 *= -1;
c1 *= -1;
}
if (a1 == 0 && b1 < 0) {
b1 *= -1;
c1 *= -1;
}

if (a2 <0) {
a2 *= -1;
b2 *= -1;
c2 *= -1;
}
if (a2 == 0 && b2 < 0) {
b2 *= -1;
c2 *= -1;
}
int g1 = gcd(a1, abs(b1));
int g2 = gcd(a2, abs(b2));
if ((g1 == 0 && c1 != 0) || (g2 == 0 && c2 != 0)) {
printf("0\n");
return 0;
}
if (g1 == 0 || g2 == 0) {
printf("-1\n");
return 0;
}

a2 *= g1;
b2 *= g1;
c2 *= g1;

a1 *= g2;
b1 *= g2;
c1 *= g2;

if (a1 == a2 && b1 == b2) {
if (c1 == c2) {
printf("-1\n");
} else {
printf("0\n");
}
} else {
printf("1\n");
}
return 0;
}