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

string a[100];
int col[100];

int main() {
    int n, m;
    cin >> n >> m;
    forn (i, n) {
        cin >> a[i];
    }
    forn (j, m) {
        col[j] = -1;
    }
    int cur = 0;
    forn (i, n) {
        set<int> s;
        forn (j, m) {
            if (a[i][j] == '#') {
                s.insert(col[j]);
            }
        }
        if (s.size() == 0) {
            continue;
        }
        if (s.size() > 1) {
            cout << "No\n";
            return 0;
        }
        int c = *s.begin();
        if (c == -1) {
            c = cur++;
        }
        forn (j, m) {
            if (a[i][j] == '#') {
                col[j] = c;
            }
            if (a[i][j] == '.' && col[j] == c) {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}