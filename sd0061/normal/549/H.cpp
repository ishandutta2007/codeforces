#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 105;

int a , b , c , d;

double check(double V) {

    double L1 = 1e60 , R1 = -1e60;
    L1 = min(L1 , (a - V) * (d - V));
    L1 = min(L1 , (a + V) * (d - V));
    L1 = min(L1 , (a - V) * (d + V));
    L1 = min(L1 , (a + V) * (d + V));

    R1 = max(R1 , (a - V) * (d - V));
    R1 = max(R1 , (a + V) * (d - V));
    R1 = max(R1 , (a - V) * (d + V));
    R1 = max(R1 , (a + V) * (d + V));

    double L2 = 1e60 , R2 = -1e60;
    L2 = min(L2 , (b - V) * (c - V));
    L2 = min(L2 , (b + V) * (c - V));
    L2 = min(L2 , (b - V) * (c + V));
    L2 = min(L2 , (b + V) * (c + V));

    R2 = max(R2 , (b - V) * (c - V));
    R2 = max(R2 , (b + V) * (c - V));
    R2 = max(R2 , (b - V) * (c + V));
    R2 = max(R2 , (b + V) * (c + V));

    if (min(R1 , R2) > max(L1 , L2))
        return 1;
    return 0;
}

void work() {
    scanf("%d%d%d%d" , &a , &b , &c , &d);
    double l = 0 , r = 2e9 , m;
    for (int i = 0 ; i < 100 ; ++ i) {
        m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m;
    }
    printf("%.10f\n" , r);
}

int main() {
    work();
    return 0;
}