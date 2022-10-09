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

typedef long double ld;

int cnt[10100];
int ones[20100];

int main() {
    forn (i, 20100) {
        forn (j, 17) {
            if (i & (1 << j)) {
                ones[i]++;
            }
        }
    }
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    forn (i, n) {
        int x;
        cin >> x; 
        cnt[x]++;
    }
    long long ans = 0;
    forn (i, 10001) {
        forn (j, i + 1) {
            if (ones[i ^ j] != k) {
                continue;
            }
            if (i == j) {
                ans += ((long long)(cnt[i]) * (cnt[i] - 1)) / 2;
            } else {
                ans += (long long)(cnt[i]) * cnt[j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}