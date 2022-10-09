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

int a[300100];
int d[100][100];
multiset<int> s;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ll sum = 0;
    forn (i, n) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
/*        for (auto x: s) {
            cerr << -x << " ";
        }
        cerr << endl;*/
        int cur = -a[i];
        if (s.empty()) {
            s.insert(cur);
            continue;
        }
        int mx = *s.begin();
        if (cur < mx) {
            s.insert(cur);
            continue;
        }
        s.erase(s.begin());
        s.insert(cur);
        s.insert(cur);
    }
    for (auto x: s) {
        sum += x;
    }
    cout << sum << endl;
    return 0;
}