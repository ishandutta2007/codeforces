#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int cnt[1100];
int ncnt[1100];

int main() {
    ios::sync_with_stdio(false);
    int n, k, x;
    cin >> n >> k >> x;
    forn (i, n) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    forn (q, k) {
        forn (i, 1100) {
            ncnt[i] = 0;
        }
        int odd = 0;
        forn (i, 1100) {
            if (!cnt[i]) {
                continue;
            }
            if (!odd) {
                ncnt[i] += cnt[i] / 2;
                ncnt[i ^ x] += (cnt[i] + 1) / 2;
            } else {
                ncnt[i ^ x] += cnt[i] / 2;
                ncnt[i] += (cnt[i] + 1) / 2;
            }
            if (cnt[i] % 2) {
                odd = 1 - odd;
            }
        }
        forn (i, 1100) {
            cnt[i] = ncnt[i];
        }
    }
    for (int i = 1099; i >= 0; --i) {
        if (cnt[i]) {
            cout << i << " ";
            break;
        }
    }
    forn (i, 1100) {
        if (cnt[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}