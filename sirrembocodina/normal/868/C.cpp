#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

int mod = 1000000007;

int cnt[20];

int main() {
    int n, k;
    cin >> n >> k;
    forn (i, n) {
        int mask = 0;
        forn (j, k) {
            int x;
            cin >> x;
            if (x == 0) {
                mask += 1 << j;
            }
        }
        cnt[mask]++;
    }
    if (cnt[(1 << k) - 1]) {
        cout << "YES\n";
        return 0;
    }
    forn (i, 1 << k) {
        forn (j, i) {
            if ((i | j) == (1 << k) - 1 && cnt[i] && cnt[j]) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
//    int N = (1 << k);
    return 0;
}