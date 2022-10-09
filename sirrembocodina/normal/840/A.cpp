#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int a[200100];
pair<int, int> b[200100];
int ans[200100];

int main() {
    ios::sync_with_stdio(false);
    int m;
    cin >> m;
    forn (i, m) {
        cin >> a[i];
    }
    forn (i, m) {
        cin >> b[i].fs;
        b[i].sc = i;
    }
    sort(b, b + m);
    sort(a, a + m);
    forn (i, m) {
        ans[b[i].sc] = a[m - i - 1];
    }
    forn (i, m) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}