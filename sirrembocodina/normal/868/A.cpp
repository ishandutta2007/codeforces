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

string a[200100];

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n;
    cin >> n;
    forn (i, n) {
        cin >> a[i];
        if (a[i] == s) {
            cout << "YES\n";
            return 0;
        }
        forn (j, i + 1) {
            if (a[j][0] == s[1] && a[i][1] == s[0]) {
                cout << "YES\n";
                return 0;
            }
            if (a[i][0] == s[1] && a[j][1] == s[0]) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}