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

int n;
int a[100100];

int main() {
    ios::sync_with_stdio(false);
    string s, a, b;
    bool was[26];
    forn (i, 26) {
        was[i] = false;
    }
    cin >> s;
    int last = -1;
    forn (i, s.size()) {
        if (was[s[i] - 'a']) {
            continue;
        }
        if (s[i] - 'a' > last + 1) {
            cout << "NO\n";
            return 0;
        }
        was[s[i] - 'a'] = true;
        last = s[i] - 'a';
    }
    cout << "YES\n";
    return 0;
}