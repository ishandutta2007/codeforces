#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <math.h>
#include <sstream>
#include <complex>
#include <string.h>
#include <algorithm>
using namespace std;

void solve();
#define mp make_pair
#define pb push_back
typedef int fknmain;
typedef long long int li;
/**
 CAUTION Is int really int?
 *
 Real solution after main function
 */
//#define int li
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef double ld;

fknmain main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
#define LL "%lld"
#else
#define LL "%I64d"
#endif
#ifndef int
#define INT "%d"
#else
#define INT LL
#endif
    solve();
    return 0;
}
int maxes[200];
int mines[200];
int used[200];
int cnt = 0;
int maxi = 0;
bool c[200][200];

void solve() {
    memset(mines,127,sizeof(mines));
    int n, m;
    char c;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> c;
            if (c == 'W') {
                maxes[i] = max(maxes[i], j);
                mines[i] = min(mines[i], j);

                maxes[i - 1] = max(maxes[i - 1], j);
                mines[i - 1] = min(mines[i - 1], j);
                used[i] = 1;
                used[i - 1] = 1;
                ++cnt;
                maxi = max(maxi, i);
            }
        }
    }
    int pos = 1;
    int ans = 0;
    for (int i = 1; i <= maxi; ++i) {
        if (i % 2) {
            if (used[i] && maxes[i] > pos) {
                ans +=  abs(maxes[i] - pos);
                pos = maxes[i];
            }
        } else {
            if (used[i] && mines[i]<pos) {
                ans+=abs(pos-mines[i]);
                pos=mines[i];
            }
        }
    }
    if(maxi==0)
        cout<<0;
    else
        cout<<ans+maxi-1;
}