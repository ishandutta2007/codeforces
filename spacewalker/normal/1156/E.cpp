#include <bits/stdc++.h>

using namespace std;

struct MISparseTable {
    vector<int> orig;
    vector<vector<int>> table;
    int n;
    MISparseTable() {}
    int getLargerIndex(int i, int j) {
//        printf("gsi %d %d\n", i, j);
        return (orig[i] > orig[j] ? i : j);
    }
    MISparseTable(vector<int> orig) : orig(orig), table(log2(orig.size()) + 5, orig), n(orig.size()) {
        iota(begin(table[0]), end(table[0]), 0);
        for (int l = 1; (1 << l) <= n; ++l) {
            for (int i = 0; i + (1 << l) <= n; ++i) {
                table[l][i] = getLargerIndex(table[l-1][i], table[l-1][i+(1<<(l-1))]);
//                printf("table %d %d %d\n", l, i, table[l][i]);
            }
        }
    }
    int getMaxIdx(int i, int j) {
        int l = log2(j - i + 1);
//        printf("gmi %d %d %d\n", i, j, l);
        return getLargerIndex(table[l][i], table[l][j+1-(1<<l)]);
    }
};

MISparseTable mi;
vector<int> lugar;

int solve(vector<int> &arr, int l, int r) {
//    printf("%d %d\n", l, r);
    if (l >= r - 1) return 0;
    int midx = mi.getMaxIdx(l, r);
    pair<int, int> rn1 = {l, midx - 1}, rn2 = {midx + 1, r};
    if (r - midx < midx - l) swap(rn1, rn2);
    // iterate over rn1: which needed pair elements can be found in rn2?
    int ans = 0; 
    for (int k = rn1.first; k <= rn1.second; ++k) {
        int pairLoc = lugar[arr[midx] - arr[k]];
        if (rn2.first <= pairLoc && pairLoc <= rn2.second) ++ans;
    }
    ans += solve(arr, rn1.first, rn1.second);
    ans += solve(arr, rn2.first, rn2.second);
    return ans;
}

int main() {
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    lugar.assign(n+1, 0);
    for (int i = 0; i < n; ++i) lugar[arr[i]] = i;
    mi = MISparseTable(arr);
    printf("%d\n", solve(arr, 0, n-1));
    return 0;
}