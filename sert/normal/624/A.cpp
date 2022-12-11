#include <bits/stdc++.h>
using namespace std;
int main() {
    double l, d, v1, v2;
    scanf("%lf%lf%lf%lf", &d, &l, &v1, &v2);
    printf("%.9f", (l - d) / (v1 + v2));
}