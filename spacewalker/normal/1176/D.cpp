#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 3000000;

bool isPrime[NMAX];
int primeIndex[NMAX], spDiv[NMAX];

int main() {
    memset(spDiv, -1, sizeof spDiv);
    for (int i = 2; i < NMAX; ++i) isPrime[i] = true;
    for (int i = 2; i < NMAX; ++i) {
        if (!isPrime[i]) continue;
        for (int j = 2 * i; j < NMAX; j += i) {
            if (spDiv[j] != -1) continue;
            isPrime[j] = false;
            spDiv[j] = i;
//            if (j == 200) printf("setting %d %d\n", j, i);
        }
    }
    int primeCount = 1;
    for (int i = 2; i < NMAX; ++i) {
        if (isPrime[i]) primeIndex[i] = primeCount++;
    }
    int n; scanf("%d", &n);
    multiset<int> b;
    for (int i = 0; i < 2 * n; ++i) {
        int x; scanf("%d", &x);
        b.insert(x);
    }
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int itc = *b.rbegin();
        if (isPrime[itc]) {
            b.erase(b.find(itc));
            b.erase(b.find(primeIndex[itc]));
            a.push_back(primeIndex[itc]);
        } else {
//            printf("%d spdiv %d\n", itc, spDiv[itc]);
            b.erase(b.find(itc));
            b.erase(b.find(itc / spDiv[itc]));
            a.push_back(itc);
        }
    }
    for (int x : a) printf("%d ", x);
    printf("\n");
    return 0;
}