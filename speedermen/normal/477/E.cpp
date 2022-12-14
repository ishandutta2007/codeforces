#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1 << 19, MaxQ = 1 << 19, MaxL = 19;

int a[MaxN], result[MaxQ], n;
int st[MaxL][MaxN], hei[MaxN];
vector < tuple <int, int, int, int> > rc[MaxQ];

inline int GetMin(int l, int r) {
    if (l > r) {
        l ^= r ^= l ^= r;
    }
    int p = hei[r - l + 1];
    return min(st[p][l], st[p][r - (1 << p) + 1]);
}

void Preprocess() {
    {
        vector <int> stk;
        for (int i = 1; i <= n; ++i) {
            while (!stk.empty() && a[stk.back()] > a[i]) {
                stk.pop_back();
            }
            stk.push_back(i);
            for (int j = 0; j < (int)rc[i].size(); ++j) {
                int r1 = get<0>(rc[i][j]), c1 = get<1>(rc[i][j]), c2 = get<2>(rc[i][j]), id = get<3>(rc[i][j]);
                int md = 0, l = 0, r = (int)stk.size() - 1;
                while (l <= r) {
                    int m = (l + r) / 2;
                    if (a[stk[m]] > c2) {
                        md = m;
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
                {
                    int l = 0, r = md - 1;
                    while (r - l > 5) {
                        int dl = l + (r - l) / 3, dr = r - (r - l) / 3;
                        int fdl = abs(i - stk[dl]) + abs(r1 - stk[dl]) + abs(c2 - a[stk[dl]]) + (min(c1, GetMin(r1, stk[dl])) < a[stk[dl]]);
                        int fdr = abs(i - stk[dr]) + abs(r1 - stk[dr]) + abs(c2 - a[stk[dr]]) + (min(c1, GetMin(r1, stk[dr])) < a[stk[dr]]);
                        if (fdl < fdr) {
                            r = dr;
                        } else {
                            l = dl;
                        }
                        result[id] = min(result[id], fdl);
                        result[id] = min(result[id], fdr);
                    }
                    for (int k = l; k <= r; ++k) {
                        int fcur = abs(i - stk[k]) + abs(r1 - stk[k]) + abs(c2 - a[stk[k]]) + (min(c1, GetMin(r1, stk[k])) < a[stk[k]]);
                        result[id] = min(result[id], fcur);
                    }
                }
                {
                    int l = md, r = (int)stk.size() - 1;
                    while (r - l > 5) {
                        int dl = l + (r - l) / 3, dr = r - (r - l) / 3;
                        int fdl = abs(i - stk[dl]) + abs(r1 - stk[dl]) + abs(c2 - a[stk[dl]]) + (min(c1, GetMin(r1, stk[dl])) < a[stk[dl]]);
                        int fdr = abs(i - stk[dr]) + abs(r1 - stk[dr]) + abs(c2 - a[stk[dr]]) + (min(c1, GetMin(r1, stk[dr])) < a[stk[dr]]);
                        if (fdl < fdr) {
                            r = dr;
                        } else {
                            l = dl;
                        }
                        result[id] = min(result[id], fdl);
                        result[id] = min(result[id], fdr);
                    }
                    for (int k = l; k <= r; ++k) {
                        int fcur = abs(i - stk[k]) + abs(r1 - stk[k]) + abs(c2 - a[stk[k]]) + (min(c1, GetMin(r1, stk[k])) < a[stk[k]]);
                        result[id] = min(result[id], fcur);
                    }
                }
            }
        }
    }
    {
        vector <int> stk;
        for (int i = n; i >= 1; --i) {
            while (!stk.empty() && a[stk.back()] > a[i]) {
                stk.pop_back();
            }
            stk.push_back(i);
            for (int j = 0; j < (int)rc[i].size(); ++j) {
                int r1 = get<0>(rc[i][j]), c1 = get<1>(rc[i][j]), c2 = get<2>(rc[i][j]), id = get<3>(rc[i][j]);
                int md = 0, l = 0, r = (int)stk.size() - 1;
                while (l <= r) {
                    int m = (l + r) / 2;
                    if (a[stk[m]] > c2) {
                        md = m;
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
                {
                    int l = 0, r = md - 1;
                    while (r - l > 5) {
                        int dl = l + (r - l) / 3, dr = r - (r - l) / 3;
                        int fdl = abs(i - stk[dl]) + abs(r1 - stk[dl]) + abs(c2 - a[stk[dl]]) + (min(c1, GetMin(r1, stk[dl])) < a[stk[dl]]);
                        int fdr = abs(i - stk[dl]) + abs(r1 - stk[dl]) + abs(c2 - a[stk[dr]]) + (min(c1, GetMin(r1, stk[dr])) < a[stk[dr]]);
                        if (fdl < fdr) {
                            r = dr;
                        } else {
                            l = dl;
                        }
                        result[id] = min(result[id], fdl);
                        result[id] = min(result[id], fdr);
                    }
                    for (int k = l; k <= r; ++k) {
                        int fcur = abs(i - stk[k]) + abs(r1 - stk[k]) + abs(c2 - a[stk[k]]) + (min(c1, GetMin(r1, stk[k])) < a[stk[k]]);
                        result[id] = min(result[id], fcur);
                    }
                }
                {
                    int l = md, r = (int)stk.size() - 1;
                    while (r - l > 5) {
                        int dl = l + (r - l) / 3, dr = r - (r - l) / 3;
                        int fdl = abs(i - stk[dl]) + abs(r1 - stk[dl]) + abs(c2 - a[stk[dl]]) + (min(c1, GetMin(r1, stk[dl])) < a[stk[dl]]);
                        int fdr = abs(i - stk[dl]) + abs(r1 - stk[dl]) + abs(c2 - a[stk[dr]]) + (min(c1, GetMin(r1, stk[dr])) < a[stk[dr]]);
                        if (fdl < fdr) {
                            r = dr;
                        } else {
                            l = dl;
                        }
                        result[id] = min(result[id], fdl);
                        result[id] = min(result[id], fdr);
                    }
                    for (int k = l; k <= r; ++k) {
                        int fcur = abs(i - stk[k]) + abs(r1 - stk[k]) + abs(c2 - a[stk[k]]) + (min(c1, GetMin(r1, stk[k])) < a[stk[k]]);
                        result[id] = min(result[id], fcur);
                    }
                }
            }
        }
    }
}


int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        st[0][i] = a[i];
    }
    for (int i = 2; i <= n; ++i) {
        hei[i] = hei[i >> 1] + 1;
    }
    for (int j = 1; j < MaxL; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
        int r1, c1, r2, c2;
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        result[i] = min(abs(r1 - r2) + (c1 > 0) + c2, abs(r2 - r1) + abs(min(c1, GetMin(r1, r2)) - c2));
        result[i] = min(result[i], abs(r2 - r1) + abs(a[r2] - c2) + (min(c1, GetMin(r1, r2)) < a[r2]));
        rc[r2].push_back(make_tuple(r1, c1, c2, i));
    }
    Preprocess();
    for (int i = 1; i <= q; ++i) {
        printf("%d\n", result[i]);
    }
    return 0;
}