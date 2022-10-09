#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

bool eq(char a, char b) {
    if ('a' <= a && a <= 'z') {
        a += 'Z' - 'z';
    }
    if ('a' <= b && b <= 'z') {
        b += 'Z' - 'z';
    }
    return a == b || a == '0' && b == 'O' || a == 'I' && b == '1' || a == 'I' && b == 'L' || a == '1' && b == 'L';
}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    bool was = false;
    forn (i, n) {
        string t;
        cin >> t;
        bool ok = t.size() == s.size();
        forn (j, min(s.size(), t.size())) {
            if (eq(s[j], t[j]) || eq(t[j], s[j])) {
                continue;
            }
            ok = false;
        }
        if (ok) {
            was = true;
        }
    }
    cout << (was ? "No\n" : "Yes\n") << endl;
    return 0;
}