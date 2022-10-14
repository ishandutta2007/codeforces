#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, x, n, m;
    cin >> k >> x >> n >> m;
    k -= 2;
    for (int f1 = 0; f1 <= 2; f1++) {
        for (int l1 = 0; l1 <= 2; l1++) {
            for (int f2 = 0; f2 <= 2; f2++) {
                for (int l2 = 0; l2 <= 2; l2++) {
                    for (int c1 = 0; c1 <= (n - (f1 != 0) - (l1 != 2)) / 2; c1++) {
                        for (int c2 = 0; c2 <= (m - (f2 != 0) - (l2 != 2)) / 2; c2++) {
                            int ff1 = f1, ll1 = l1, ff2 = f2, ll2 = l2, cc1 = c1, cc2 = c2;
                            for (int _ = 0; _ < k; _++) {
                                int ff3 = ff1;
                                int ll3 = ll2;
                                int cc3 = min(x+1010, cc1+cc2+(ll1 == 0 && ff2 == 2));
                                ff1 = ff2;
                                ll1 = ll2;
                                cc1 = cc2;
                                ff2 = ff3;
                                ll2 = ll3;
                                cc2 = cc3;
                            }
                            if (cc2 == x) {
                                if (n != 1 || f1 == l1) {
                                    if (m != 1 || f2 == l2) {
                                        int cr1 = c1, cr2 = c2;
                                        string s1 = "";
                                        s1 += (char) ('A' + f1);
                                        for (int i = 1; i < n-1; i++) {
                                            if (cr1) {
                                                if (s1.back() == 'A') {
                                                    s1 += 'C';
                                                    cr1--;
                                                } else {
                                                    s1 += 'A';
                                                }
                                            } else {
                                                s1 += 'B';
                                            }
                                        }
                                        if (n != 1) s1 += (char) ('A' + l1);
                                        string s2 = "";
                                        s2 += (char) ('A' + f2);
                                        for (int i = 1; i < m-1; i++) {
                                            if (cr2) {
                                                if (s2.back() == 'A') {
                                                    s2 += 'C';
                                                    cr2--;
                                                } else {
                                                    s2 += 'A';
                                                }
                                            } else {
                                                s2 += 'B';
                                            }
                                        }
                                        if (m != 1) s2 += (char) ('A' + l2);
                                        cout << s1 << '\n' << s2 << '\n';
                                        exit(0);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "Happy new year!\n";
}