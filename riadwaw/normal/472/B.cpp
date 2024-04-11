/**
 * BE CAREFUL!! I have define int li sometimes
 */

//#define _GLIBCXX_DEBUG

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <bitset>
#include <map>
#include <cassert>
#include <memory.h>
#include <limits>
#include <numeric>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
//typedef pair<int, int> pi;

void solve();

void prec();


#define FILENAME "souvenir"

int main() {
    string s = FILENAME;
#ifdef DEBUG
    freopen("/Users/RiaD/Contests/Contests/input", "r", stdin);
    //freopen("/Users/RiaD/Contests/Contests/output", "w", stdout);
    //cout<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    cout.sync_with_stdio(0);
    cout.precision(20);
    cout << fixed;
    //prec();
    int tests = 1;
    //cin >> tests;

    while (tests--) {
        solve();
    }
#ifdef DEBUG
    //cerr<<"\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
    return 0;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for(int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    sort(all(x));

    vector<int> y;
    for(int i = n - 1; i >= 0; i -= k) {
        y.push_back(x[i]);
    }


    int ans =0;

    for(int i = 0; i < y.size(); ++i) {
        ans += (y[i] - 1) * 2;
    }

    cout << ans;
}