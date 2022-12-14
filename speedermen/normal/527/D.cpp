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

int n, x[nmax], w[nmax];
int ord[nmax];
vector < int > all;
int fen[nmax];
stack < int > st;

bool cmp(int i, int j) {
    return x[i] < x[j];
}

int get(int r) {
    int ans = 0;
    for(;r >= 0; r &= r + 1, --r)
        ans += fen[r];
    return ans;
}

void upd(int r, int val) {
    for(;r < nmax; r |= r + 1)
        fen[r] += val;
}

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    //freopen("distance.in", "r", stdin); freopen("distance.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d", &x[i], &w[i]);
        all.pb(x[i] + w[i]);
        ord[i] = i;
    }
    sort(ord + 1, ord + 1 + n, cmp);
    int ans = 0, Max = -2e9;
    multiset < int > s;
    for(int i = 1; i <= n; ++i) {
        if(!s.empty() && x[ord[i]] - w[ord[i]] < *s.rbegin()) {
            if(x[ord[i]] + w[ord[i]] < *s.rbegin()) {
                s.erase(--s.end());
                s.insert(x[ord[i]] + w[ord[i]]);
            }
            continue;
        }
        s.insert(x[ord[i]] + w[ord[i]]);
        ++ans;
    }
    cout << ans << endl;
    getchar(); getchar();
    return 0;
}