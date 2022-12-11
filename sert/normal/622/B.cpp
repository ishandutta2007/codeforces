#include <bits/stdc++.h>
using namespace std;
int h, m, a;
int main() {
    scanf("%d:%d", &h, &m);
    scanf("%d", &a);
    m = (m + a + h * 60) % 1440;
    printf("%02d:%02d", m / 60, m % 60);

}