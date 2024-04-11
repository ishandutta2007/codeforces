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

string s[110];

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    forn (i, n) {
        cin >> s[i];
    }
    forn (i, k) {
        int mn = 10;
        int x = -1, y = -1;
        forn (j, n) {
            forn (l, 12) {
                if (s[j][l] != '.') {
                    continue;
                }
                int a = 0;
                if (l && s[j][l - 1] == 'S') {
                    a++;
                }
                if (l < 12 && s[j][l + 1] == 'S') {
                    a++;
                }
                if (a < mn) {
                    mn = a;
                    x = j;
                    y = l;
                }
            }
        }
        s[x][y] = 'x';
    }
    int sum = 0;
    forn (i, n) {
        forn (j, 11) {
            if ((s[i][j] == 'S' || s[i][j] == 'P' || s[i][j] == 'x') &&
                (s[i][j + 1] == 'S' || s[i][j + 1] == 'P' || s[i][j + 1] == 'x')) {
                sum += s[i][j] == 'S';
                sum += s[i][j + 1] == 'S';
            }
        }
    }
    cout << sum << endl;
    forn (i, n) {
        cout << s[i] << endl;
    }
    return 0;
}