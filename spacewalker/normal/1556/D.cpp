#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int getOR(int i, int j) {
    printf("or %d %d\n", i + 1, j + 1);
    fflush(stdout);
    int x; scanf("%d", &x);
    return x;
}

int getAND(int i, int j) {
    printf("and %d %d\n", i + 1, j + 1);
    fflush(stdout);
    int x; scanf("%d", &x);
    return x;
}

void determine(int a, int b, int c) {
    vector<int> ands{getAND(a, b), getAND(b, c), getAND(c, a)};
    vector<int> ors{getOR(a, b), getOR(b, c), getOR(c, a)};
    arr[a] = arr[b] = arr[c] = 0;
    for (int x = 0; x < 30; ++x) {
        vector<int> abits(3), obits(3);
        for (int i = 0; i < 3; ++i) {
            abits[i] = (ands[i] & (1 << x));
            obits[i] = (ors[i] & (1 << x));
        }
        int aposct = 0, oposct = 0;
        for (int i = 0; i < 3; ++i) if (abits[i] > 0) ++aposct;
        for (int i = 0; i < 3; ++i) if (obits[i] > 0) ++oposct;
        vector<int> toSet;
        if (aposct == 3) {
            toSet = {a, b, c};
        } else if (aposct == 1) {
            if (abits[0] > 0) toSet = {a, b};
            else if (abits[1] > 0) toSet = {b, c};
            else if (abits[2] > 0) toSet = {c, a};
        } else if (oposct == 0) {
            toSet = {};
        } else {
            if (obits[0] == 0) toSet = {c};
            else if (obits[1] == 0) toSet = {a};
            else if (obits[2] == 0) toSet = {b};
        }
        for (int v : toSet) arr[v] |= (1 << x);
    }
}

void determine(int known, int unknown) {
    int a = getAND(known, unknown), o = getOR(known, unknown);
    int x = o & (~a);
    arr[unknown] = arr[known] ^ x;
}

int main() {
    int n, k; scanf("%d %d", &n, &k);
    arr.assign(n, -1);
    for (int i = 0; i + 2 < n; i += 3) {
        determine(i, i + 1, i + 2);
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] == -1) determine(0, i);
    }
    if (false) {
        fprintf(stderr, "!! array ");
        for (int i = 0; i < n; ++i) fprintf(stderr, "%d ", arr[i]);
        fprintf(stderr, "\n");
        fflush(stderr);
    }
    sort(begin(arr), end(arr));
    printf("finish %d\n", arr[k - 1]);
}