#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cassert>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

const ll mod = 1000000007;

int n;
char s[110][110];
bool g[26][26];
char ans[27];

int main() {
    scanf("%d", &n);
    forn (i, n) {
        scanf("%s", s[i]);
        if (!i) {
            continue;
        }
        int m = min(strlen(s[i]), strlen(s[i - 1]));
        int j = 0;
        while (j < m && s[i][j] == s[i - 1][j]) {
            ++j;
        }
        if (j < m) {
            g[s[i - 1][j] - 'a'][s[i][j] - 'a'] = true;
//            printf("%c%c\n", s[i - 1][j], s[i][j]);
        } else if (strlen(s[i - 1]) > strlen(s[i])) {
            printf("Impossible\n");
            return 0;
        }
    }
    forn (i, 26) {
        forn (j, 26) {
            bool ok = true;
            forn (k, i) {
                if (ans[k] == j + 'a') {
                    ok = false;
                }
            }
            forn (k, 26) {
                if (!g[k][j]) {
                    continue;
                }
                bool was = false;
                forn (l, i) {
                    if (ans[l] == k + 'a') {
                        was = true;
                    }
                }
                if (!was) {
                    ok = false;
                }
            }
            if (ok) {
                ans[i] = j + 'a';
                break;
            }
        }
        if (!ans[i]) {
            printf("Impossible\n");
//            printf("%s\n", ans);
            return 0;
        }
    }
    printf("%s\n", ans);
    return 0;
}