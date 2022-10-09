#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forn2(i, n) for (i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int s[1010];
bool nl[1010];
int p[1010];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    forn (i, n - 1) {
        cin >> p[i + 1];
        --p[i + 1];
        nl[p[i + 1]] = true;
    }
    forn (i, n - 1) {
        if (!nl[i + 1]) {
            ++s[p[i + 1]];
        }
    }
    bool ok = true;
    forn (i, n) {
//        cerr << nl[i] << " " << s[i] << endl;
        if (nl[i] && s[i] < 3) {
            ok = false;
        }
    }
    cout << (ok ? "Yes\n" : "No\n");
    return 0;
}