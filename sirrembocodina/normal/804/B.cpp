#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <iostream>

using namespace std;

#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair

typedef unsigned int uint;

const int mod = 1000000007;

char s[1000100];
int f[1000100];

int main() {
    int n;
    scanf("%s", s);
    n = strlen(s);
    f[0] = 0;
    forn (i, n) {
        f[i + 1] = (1 + 2 * f[i]) % mod;
    }
    int cur = 0, ans = 0;
    forn (i, n) {
        if (s[i] == 'a') {
            cur++;
        } else {
            ans += f[cur];
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}