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
const int M = 1000000007;
int SOMSM = 6;
int ahaha = (int) 1e18;

struct pt {
    int x, y;
};

vector<pt> MDIYN;

int DIST(pt a, pt b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool comp(pt a, pt b) {
    return a.y < b.y;
}
vector<pt> B;


void YAMETLAYAMETLA(int l, int r) {
    if (l >= r) {
        return;
    }
    if (r - l == 1) {
        ahaha = min(ahaha, DIST(MDIYN[l], MDIYN[r]));
        return;
    }
    if (r - l <= SOMSM) {
        for (int i = l; i < r; i++) {
            for (int j = i + 1; j <= r; j++) {
                ahaha = min(ahaha, DIST(MDIYN[i], MDIYN[j]));
            }
        }
        return;
    }
    int m = (l + r) / 2;
    YAMETLAYAMETLA(l, m);
    YAMETLAYAMETLA(m + 1, r);
    int x = MDIYN[m].x;
    B = {};
    for (int i = l; i <= r; i++) {
        if (abs(MDIYN[i].x - x) <= ahaha) {
            B.pb(MDIYN[i]);
        } else {
            break;
        }
    }
    sort(B.begin(), B.end(), comp);
    for (int i = 0; i < (int) B.size(); i++) {
        for (int j = i - 1; j >= max(0LL, i-10); j--) {
            ahaha = min(ahaha, DIST(B[i], B[j]));
        }
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 1; i < n; i++) A[i] += A[i - 1];
    for (int i = 0; i < n; i++) {
        pt pot;
        pot.x = i;
        pot.y = A[i];
        MDIYN.pb(pot);
    }
    YAMETLAYAMETLA(0, n - 1);
    cout << ahaha;
}