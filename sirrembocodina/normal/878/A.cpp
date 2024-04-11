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

int x[15];

int main() {
    ios::sync_with_stdio(false);
    forn (i, 15) {
        x[i] = 2;
    }
    int n;
    cin >> n;
    forn (i, n) {
        string t;
        int a;
        cin >> t >> a;
        if (t[0] == '|') {
            forn (i, 10) {
                if (a & (1 << i)) {
                    x[i] = 1;
                }
            }
        } else if (t[0] == '&') {
            forn (i, 10) {
                if ((a & (1 << i)) == 0) {
                    x[i] = 0;
                }
            }
        } else {
            forn (i, 10) {
                if (a & (1 << i)) {
                    x[i] = 1 - x[i];
                }
            }
        }
    }
    cout << "3\n";
    int a = 0;
    forn (i, 10) {
        if (x[i] != 0) {
            a += 1 << i;
        }
    }
    cout << "& " << a << endl;
    a = 0;
    forn (i, 10) {
        if (x[i] == 1) {
            a += 1 << i;
        }
    }
    cout << "| " << a << endl;
    a = 0;
    forn (i, 10) {
        if (x[i] == -1) {
            a += 1 << i;
        }
    }
    cout << "^ " << a << endl;
    return 0;
}