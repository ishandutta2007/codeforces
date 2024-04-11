#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int a[110];

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int sum = 0;
    forn (i, n) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    int ans = 0;
    forn (i, n + 1) {
        if (sum * 2 >= 9 * n) {
            cout << i << endl;
            return 0;
        }
        sum -= a[i];
        sum += 5;
    }
    return 0;
}