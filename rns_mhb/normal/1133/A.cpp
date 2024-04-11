#include<bits/stdc++.h>
using namespace std;

int main() {
    int h1, m1, h2, m2;
    scanf("%d:%d", &h1, &m1);
    scanf("%d:%d", &h2, &m2);
    int h = h1 + h2 >> 1, m = m1 + m2 >> 1;
    if(h1 + h2 & 1) m += 30;
    h += m / 60, m %= 60;
    printf("%02d:%02d\n", h, m);
}