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

typedef long double ld;

string s;
char ans[210][1010];
int n, h, cur = 0;

void rec(int i, int d) {
    if (i == n) {
        return;
    }
    if (s[i] == '[') {
        forn (j, d) {
            ans[h + j][cur] = '|';
            ans[h - j][cur] = '|';
        }
        ans[h + d][cur] = '+';
        ans[h - d][cur] = '+';
        ++cur;
        ans[h + d][cur] = '-';
        ans[h - d][cur] = '-';
        rec(i + 1, d - 1);
        return;
    }
    ++d;
    if (s[i - 1] == '[') {
        cur += 3;
    }
    ans[h + d][cur - 1] = '-';
    ans[h - d][cur - 1] = '-';
    forn (j, d) {
        ans[h + j][cur] = '|';
        ans[h - j][cur] = '|';
    }
    ans[h + d][cur] = '+';
    ans[h - d][cur] = '+';
    ++cur;
    rec(i + 1, d);
}

int main() {
    forn (i, 210) {
        forn (j, 1010) {
            ans[i][j] = ' ';
        }
    }
    cin >> n;
    cin >> s;
    n = s.size();
    int b = 0;
    forn (i, n) {
        if (s[i] == '[') {
            ++b;
        } else {
            --b;
        }
        h = max(h, b);
    }
    rec(0, h);
    forn (i, 2 * h + 1) {
        ans[i][cur] = 0;
        cout << ans[i] << endl;
    }
    return 0;
}