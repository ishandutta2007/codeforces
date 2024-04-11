#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

const int max_len1 = 16;
const int max_len = 16;
bool mask[210][max_len + 1][1 << max_len];
string pref[210];
string suf[210];
int sz[210];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
//    n = 100;
    forn (k, n) {
        string s;
        cin >> s;
//        s = "0";
        sz[k] = s.size();
        mask[k][0][0] = true;
        forn (l, max_len1 + 1) {
            if (l == 0) {
                continue;
            }
            forn (a, 1 << l) {
                forn (i, s.size() - l + 1) {
                    bool ok = true;
                    forn (j, l) {
                        if (s[i + l - 1 - j] != '0' + bool(a & (1 << j))) {
                            ok = false;
                        }
                    }
                    if (ok) {
                        mask[k][l][a] = true;
                        break;
                    }
                }
            }
        }
        forn (i, min(max_len, int(s.size()))) {
            pref[k] += s[i];
        }
        forn (i, min(max_len, int(s.size()))) {
            suf[k] += s[s.size() - min(max_len, int(s.size())) + i];
        }
    }
    int m;
    cin >> m;
//    m = 100;
    forn (q, m) {
        int k = n + q;
        int x, y;
        cin >> x >> y;
//        x = y = n + q;
        --x;
        --y;
        sz[k] = min(100000, sz[x] + sz[y]);
        mask[k][0][0] = true;
        int ans = 0;
        forn (l, max_len + 1) {
            if (l == 0) {
                continue;
            }
            forn (a, 1 << l) {
                if (mask[x][l][a] || mask[y][l][a]) {
                    mask[k][l][a] = true;
                }
            }
            forn (i, min(l, int(pref[y].size()) + 1)) {
                if (i == 0 || l - i > int(suf[x].size())) {
                    continue;
                }
                int msk = 0;
                forn (j, l - i) {
                    msk <<= 1;
                    msk += suf[x][int(suf[x].size()) - l + i + j] == '1';
                }
                forn (j, i) {
                    msk <<= 1;
                    msk += pref[y][j] == '1';
                }
                mask[k][l][msk] = true;
//                cerr << msk << endl;
            }
            bool ok = true;
            forn (a, 1 << l) {
                if (!mask[k][l][a]) {
                    ok = false;
                }
            }
            if (ok) {
                ans = l;
            }
        }
        forn (i, pref[x].size()) {
            if (pref[k].size() == max_len) {
                break;
            }
            pref[k] += pref[x][i];
        }
        forn (i, pref[y].size()) {
            if (pref[k].size() == max_len) {
                break;
            }
            pref[k] += pref[y][i];
        }
        if (suf[y].size() < max_len) {
            forn (i, max_len - int(suf[y].size())) {
                if (int(suf[x].size()) - max_len + int(suf[y].size()) + i < 0) {
                    continue;
                }
//                cerr << suf[x].size() - max_len + suf[y].size() + i << " ";
                suf[k] += suf[x][int(suf[x].size()) - max_len + int(suf[y].size()) + i];
            }
        }
        forn (i, suf[y].size()) {
            if (suf[k].size() == max_len) {
                break;
            }
            suf[k] += suf[y][i];
        }
//        cerr << endl;
//        cerr << pref[k] << endl << suf[k] << endl;
//        cerr << endl;
        cout << ans << endl;
    }
    return 0;
}