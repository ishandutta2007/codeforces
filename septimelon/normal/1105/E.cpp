#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-7;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int ques = 0;

int getupd(int cv, int n, vector<int>& maxposse, const vector<int>& cc) {
    ++ques;
    /*if ((ques & 1048575) == 0) {
        cout << ques << " ";
    }*/
    if (maxposse[cv] >= 0) {
        return maxposse[cv];
    }
    int forb = 0;
    for (int i = 0; i < 20; ++i) {
        if (cv & (1 << i)) {
            forb |= cc[i];
        }
    }
    if (forb & cv) {
        for (int i = 0; i < 20; ++i) {
            if (cv & (1 << i)) {
                maxposse[cv] = max(maxposse[cv], getupd(cv ^ (1 << i), n - 1, maxposse, cc));
            }
        }
    }
    else {
        maxposse[cv] = n;
    }
    return maxposse[cv];
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> cll(20, 0), crl(20, 0), clr(20, 0), crr(20, 0);
    map<string, int> ntoi;
    int cincl = 0, cincr = 0;
    for (int i = 0; i <= n; ++i) {
        int t;
        string cs;
        if (i < n) {
            cin >> t;
        }
        else {
            t = 1;
        }
        if (t == 1) {
            for (int i = 0; i < 20; ++i) {
                if (cincl & (1 << i)) {
                    cll[i] |= (cincl ^ (1 << i));
                    clr[i] |= cincr;
                }
                if (cincr & (1 << i)) {
                    crl[i] |= cincl;
                    crr[i] |= (cincr ^ (1 << i));
                }
            }
            cincl = 0;
            cincr = 0;
        }
        else {
            cin >> cs;
            if (ntoi.count(cs) == 0) {
                ntoi[cs] = ntoi.size();
            }
            if (ntoi[cs] < 20) {
                cincl |= (1 << ntoi[cs]);
            }
            else {
                cincr |= (1 << (ntoi[cs] - 20));
            }
        }
    }

    vector<int> maxpossel(1 << 20, -1), maxposser(1 << 20, -1);
    maxpossel[0] = 0;
    maxposser[0] = 0;
    getupd((1 << 20) - 1, 20, maxpossel, cll);
    getupd((1 << 20) - 1, 20, maxposser, crr);

    int ans = 0;
    for (int lv = 0; lv < (1 << 20); ++lv) {
        int forbr = 0;
        for (int i = 0; i < 20; ++i) {
            if (lv & (1 << i)) {
                forbr |= clr[i];
            }
        }
        ans = max(ans, maxpossel[lv] + maxposser[((1 << 20) - 1) ^ forbr]);
    }

    cout << ans + m - 40 << "\n";

    return 0;
}