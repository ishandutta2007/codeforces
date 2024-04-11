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

    vector<int> text;
    text.reserve(200000);
    int n, m;
    cin >> n >> m;
    if(m == 1) {
        cout << n << "\n";
        return;
    }
    int first;
    cin >> first;
    for(int i = 1; i < n; ++i) {
        int cur;
        cin >> cur;
        text.push_back(first - cur);
        first = cur;
    }

    vector<int> search;
    search.reserve(200000);
    //cin >> n;

    cin >> first;
    for(int i = 1; i < m; ++i) {
        int cur;
        cin >> cur;
        search.push_back(first - cur);
        first = cur;
    }


    vector<int> s;
    s.reserve(200000);

    for(int x: search) {
        s.push_back(x);
    }
    s.push_back(1000000111);
    for(int x: text) {
        s.push_back(x);
    }


     n = (int) s.size();
    vector<int> pi (n);
    int ans = 0;
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
        if(j == search.size())

            ++ans;
    }

    cout << ans << "\n";

}