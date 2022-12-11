#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> p(n);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
    vector<int> exInc(n), exDec(n);
    for (int i = 1; i < n; ++i) exInc[i] = (p[i] > p[i-1] ? exInc[i-1] + 1 : 0);
    for (int i = n - 2; i >= 0; --i) exDec[i] = (p[i] > p[i+1] ? exDec[i+1] + 1 : 0);
    int maxRun = max(*max_element(begin(exInc), end(exInc)), *max_element(begin(exDec), end(exDec)));
//    printf("mr %d\n", maxRun);
    vector<int> goodPeaks;
    for (int i = 0; i < n; ++i) {
//        printf("d %d %d\n", exInc[i], exDec[i]);
        if (exInc[i] == maxRun || exDec[i] == maxRun) goodPeaks.push_back(i);
    }
    if (goodPeaks.size() != 1) printf("0\n");
    else {
        int x = exInc[goodPeaks[0]], y = exDec[goodPeaks[0]];
        if (x > y) swap(x, y);
        printf("%d\n", (x == y && x % 2 == 0) ? 1 : 0);
    }
}