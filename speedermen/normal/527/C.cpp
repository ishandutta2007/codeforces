#pragma comment(linker, "/STACK:100000000")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstdlib>
#include <complex>
#include <sstream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <map>
#include <set>

using namespace std;

typedef unsigned long long ull;
typedef complex < double > cd;
typedef long double ld;
typedef long long ll;

#define ppb pop_back
#define pb push_back
#define mp make_pair
#define fs first
#define sd second

#define inf 1000000007
#define nmax 200010
#define mmax 100010
#define eps 1e-9

int w, h;
int n;
pair < char, int > que[nmax];
int hh[nmax], ww[nmax];
int wx[nmax], wy[nmax];
int sx[nmax], sy[nmax];
int X, Y;
long long ans[nmax];

int get(int p[], int v) {
    if(v == p[v]) {
        return v;
    }
    return p[v] = get(p, p[v]);
}

void unite(int p[], int s[], int a, int b, int &mx) {
    a = get(p, a);
    b = get(p, b);
    if(a == b) return;
    if(s[a] > s[b]) {
        swap(a, b);
    }
    p[a] = b;
    s[b] += s[a];
    mx = max(mx, s[b]);
}

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    //freopen("distance.in", "r", stdin); freopen("distance.out", "w", stdout);
    scanf("%d%d%d",  &w, &h, &n);
    for(int i = 1; i <= n; ++i) {
        scanf("\n%c%d", &que[i].fs, &que[i].sd);
        if(que[i].fs == 'H') {
            hh[que[i].sd] = 1;
        } else {
            ww[que[i].sd] = 1;
        }
    }
    for(int i = 1; i <= w; ++i) wx[i] = i, sx[i] = 1;
    for(int i = 1; i <= h; ++i) wy[i] = i, sy[i] = 1;
    X = Y = 1;
    for(int i = 1; i < w; ++i) {
        if(!ww[i]) {
            unite(wx, sx, i, i + 1, X);
        }
    }
    for(int i = 1; i < h; ++i) {
        if(!hh[i]) {
            unite(wy, sy, i, i + 1, Y);
        }
    }
    for(int i = n; i >= 1; --i) {
        ans[i] = 1LL * X * Y;
        if(que[i].fs == 'H') {
            unite(wy, sy, que[i].sd, que[i].sd + 1, Y);
        } else {
            unite(wx, sx, que[i].sd, que[i].sd + 1, X);
        }
    }
    for(int i = 1; i <= n; ++i) {
        cout << ans[i] << "\n";
    }
    getchar(); getchar();
    return 0;
}