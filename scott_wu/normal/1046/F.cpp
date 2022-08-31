#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, X, F;
    scanf("%d", &N);
    vector<int> wallets(N);

    for (int i = 0; i < N; i++)
        scanf("%d", &wallets[i]);

    scanf("%d %d", &X, &F);
    long long total = 0;

    for (int money : wallets)
        if (money > X)
            total += (money - X - 1) / (X + F) + 1;

    printf("%lld\n", total * F);
}