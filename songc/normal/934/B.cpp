#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    scanf("%d", &N);
    if (N > 36) {
        printf("-1");
        return 0;
    }
    for (; N>1; N-=2) printf("8");
    if (N) printf("6");
    return 0;
}