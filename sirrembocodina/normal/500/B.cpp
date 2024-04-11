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

int n, a[310], w[310];
bool used[310];
char s[310][310], can[310][310];

void dfs(int v) {
    used[v] = true;
    forn (i, n) {
        if (!used[i] && s[v][i] == '1') {
            dfs(i);
        }
    }
}

int main() {
    scanf("%d", &n);
    forn (i, n) {
        scanf("%d", &a[i]);
        --a[i];
        w[a[i]] = i;
    }
    forn (i, n) {
        scanf("%s", s[i]);
    }
    forn (i, n) {
        forn (j, n) {
            used[j] = false;
        }
        dfs(i);
        forn (j, n) {
            can[i][j] = used[j];
        }
    }
    forn (i, n) {
        used[i] = false;
    }
    forn (i, n) {
        forn (j, n) {
            if (!used[j] && can[i][w[j]]) {
                used[j] = true;
                printf("%d ", j + 1);
                break;
            }
        }
    }
    return 0;
}