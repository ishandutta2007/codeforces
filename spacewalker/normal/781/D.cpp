#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int NMAX = 500;
constexpr int LMAX = 63;

bool pstart[LMAX][NMAX][NMAX], bstart[LMAX][NMAX][NMAX];

bitset<NMAX> psRows[LMAX][NMAX], psCols[LMAX][NMAX],
    bsRows[LMAX][NMAX], bsCols[LMAX][NMAX];

void writeMultiplication(int n, bool c[NMAX][NMAX], bitset<NMAX> aRows[NMAX], bitset<NMAX> bCols[NMAX]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = (aRows[i] & bCols[j]).count() > 0;
        }
    }
}

void prepareSplit(int n, bool src[NMAX][NMAX], bitset<NMAX> dstRows[NMAX], bitset<NMAX> dstCols[NMAX]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dstRows[i][j] = dstCols[j][i] = src[i][j];
        }
    }
}

template<class T>
void uniqueify(vector<T> &a) {
    sort(begin(a), end(a));
    a.erase(unique(begin(a), end(a)), end(a));
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int v, u, t; scanf("%d %d %d", &v, &u, &t);
        --v; --u;
        if (t == 0) pstart[0][v][u] = true;
        else bstart[0][v][u] = true;
    }
    prepareSplit(n, pstart[0], psRows[0], psCols[0]);
    prepareSplit(n, bstart[0], bsRows[0], bsCols[0]);
    for (int i = 1; i < LMAX; ++i) {
//        writeMultiplication(n, pstart[i], pstart[i-1], bstart[i-1]);
//        writeMultiplication(n, bstart[i], bstart[i-1], pstart[i-1]);
        writeMultiplication(n, pstart[i], psRows[i-1], bsCols[i-1]);
        writeMultiplication(n, bstart[i], bsRows[i-1], psCols[i-1]);
        prepareSplit(n, pstart[i], psRows[i], psCols[i]);
        prepareSplit(n, bstart[i], bsRows[i], bsCols[i]);
    }
    int highestGood = -1;
    for (int i = 0; i < LMAX; ++i) {
        bool isGood = false;
        for (int j = 0; j < n; ++j) {
//            printf("can we go to layer %d to %d? %d\n", i, j, (int)pstart[i][0][j]);
            if (pstart[i][0][j]) isGood = true;
        }
        if (isGood) highestGood = i;
    }
    if (highestGood == -1) {
        printf("0\n");
        return 0;
    }
    ll ans = 1LL << highestGood;
    bool curStartB = true;
    vector<int> cIsAt;
    for (int i = 0; i < n; ++i) if (pstart[highestGood][0][i]) cIsAt.push_back(i);
    for (int i = highestGood - 1; i >= 0; --i) {
        vector<int> canNext;
        for (int v : cIsAt) for (int j = 0; j < n; ++j) if ((curStartB ? bstart : pstart)[i][v][j]) canNext.push_back(j);
        uniqueify(canNext);
        if (canNext.empty()) continue;
        else {
            cIsAt = canNext;
            curStartB = !curStartB;
            ans += 1LL << i;
        }
    }
    if (ans > 1000000000000000000) {
        printf("-1\n");
    } else {
        printf("%lld\n", ans);
    }
    return 0;
}