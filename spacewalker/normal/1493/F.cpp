#include <bits/stdc++.h>

using namespace std;
using rowQuerier = function<bool(int, int, int)>;
constexpr int NMAX = 2000;

vector<int> pdivs[NMAX];
int divCount[NMAX];

bool match(int h, int w, int i1, int j1, int i2, int j2) {
    printf("? %d %d %d %d %d %d\n", h, w, i1 + 1, j1 + 1, i2 + 1, j2 + 1);
    fflush(stdout);
    int ans; scanf("%d", &ans);
    return (ans == 1);
}

// check if the range between i to j
// can be divided into k equal parts
bool isPeriodic(int i, int j, int k, rowQuerier qfunc) {
//    fprintf(stderr, "period check %d %d %d\n", i, j, k);
    auto uncompress = [&] (int ci, int cj) {
        int bsize = (j - i + 1) / k;
        return pair<int, int>(i + bsize * ci, i + bsize * (cj + 1) - 1);
    };
    auto makeBlockQuery = [&] (int i1, int i2, int h) {
        auto [pi, pj] = uncompress(i1, i1 + h - 1);
        auto [qi, qj] = uncompress(i2, i2 + h - 1);
        return qfunc(pi, qi, pj - pi + 1);
    };
    int sureEqual = 1;
    while (2 * sureEqual <= k) {
        if (!makeBlockQuery(0, sureEqual, sureEqual)) return false;
        sureEqual *= 2;
    }
    int remWidth = k - sureEqual;
    if (remWidth == 0) return true;
    return makeBlockQuery(0, k - remWidth, remWidth);
}

// qfunc takes in i1 i2 h
// and makes the corresponding match query
// returns number of "divisions" the row has (so not technically the period)
int getRowPeriod(int n, rowQuerier qfunc) {
    if (n == 1) return 1;
    int ans = 1;
    for (int p : pdivs[n]) {
        int rangeEnd = n;
        while (rangeEnd % p == 0 && isPeriodic(0, rangeEnd - 1, p, qfunc)) {
            rangeEnd /= p;
        }
        ans *= (n / rangeEnd);
    }
    return ans;
}

int main() {
    for (int i = 2; i < NMAX; ++i) {
        if (pdivs[i].size() > 0) continue;
        for (int j = i; j < NMAX; j += i) pdivs[j].push_back(i);
    }
    for (int i = 1; i < NMAX; ++i) for (int j = i; j < NMAX; j += i) ++divCount[j];
    int n, m; scanf("%d %d", &n, &m);
    int rowSC = 1, colSC = 1; // these are split coefficients
    rowQuerier rq = [&] (int i1, int i2, int h) {
        return match(h, m, i1, 0, i2, 0); 
    };
    rowQuerier cq = [&] (int i1, int i2, int h) {
        return match(n, h, 0, i1, 0, i2);
    };
    rowSC = getRowPeriod(n, rq);
    colSC = getRowPeriod(m, cq);
    fprintf(stderr, "?? %d %d", rowSC, colSC);
    printf("! %d\n", divCount[rowSC] * divCount[colSC]);
    fflush(stdout);
}