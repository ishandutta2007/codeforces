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
    cin >> n;
    if (n % 2 ) {
        cout << "contest\n";
    } else {
        cout << "home\n";
    }
    return 0;
    string s, a, b;
    cin >> s;
    int ans = 0;
    forn (i, n) {
        cin >> a;
        if (a[0] == s[0] &&
            a[1] == s[1] &&
            a[2] == s[2]) {
            ans++;
        }
        if (a[5] == s[0] &&
            a[6] == s[1] &&
            a[7] == s[2]) {
            ans--;
        }
    }
    if (ans) {
        cout << "contest\n";
    } else {
        cout << "home\n";
    }
}