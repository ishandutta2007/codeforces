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

char s[100100];

int main() {
    int n;
    cin >> s;
    n = strlen(s);
    int last = 0, a = 0, cnt = 0;
    forn (i, n) {
        if (s[i] == '#') {
            s[i] = ')';
            last = i;
            ++cnt;
        }
        if (s[i] == '(') {
            ++a;
        } else {
            --a;
        }
    }
    if (a < 0) {
        printf("-1\n");
        return 0;
    }
    int b = 0;
    forn (i, n) {
        if (s[i] == '(') {
            ++b;
        } else {
            --b;
        }
        if (i == last) {
            b -= a;
        }
        if (b < 0) {
            printf("-1\n");
            return 0;
        }
    }
    forn (i, cnt - 1) {
        printf("1\n");
    }
    printf("%d\n", a + 1);
    return 0;
}