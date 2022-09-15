/**
 * BE CAREFUL!! I have define int li
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

int timer;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

void prec();

li det(vector<vector<li>> vector);

#define FILENAME "souvenir"

int main(){
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
    //rprec();
    int t = 1;
    //cin >> t;
    while (t--) {
        ++timer;
        solve();
    }
#ifdef DEBUG
    //cerr<<"\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
    return 0;
}

const int mod = 1000000007;

li binpow(li a, int b) {
    if(!b)
        return 1;
    if(b & 1)
        return binpow(a, b - 1) * a % mod;
    return binpow(a * a % mod, b / 2);
}

void solve() {
    string s;
    cin >> s;
    vector<int> len(10);
    vector<li> ost(10);
    int k;
    cin >> k;
    for(int i = 0; i < 10; ++i) {
        len[i] = 1;
        ost[i] = i;
    }
    vector<string> q(k);
    for(int i = 0; i < k;++i) {
        cin >> q[i];
    }

    for(int i = k - 1; i >= 0; --i) {
        int newLen = 0;
        li newOst = 0;
        for(int j = 3; j < q[i].size(); ++j) {
            int c = q[i][j] - '0';
            newLen += len[c];
            newLen %= mod - 1;
            newOst *= binpow(10, len[c]);
            newOst += ost[c];
            newOst %= mod;
        }

        len[q[i][0] - '0'] = newLen;
        ost[q[i][0] - '0'] = newOst;


    }

    {
        int newLen = 0;
        li newOst = 0;
        for(int j = 0; j < s.size(); ++j) {
            int c = s[j] - '0';
            newLen += len[c];
            newLen %= mod - 1;
            newOst *= binpow(10, len[c]);
            newOst += ost[c];
            newOst %= mod;
        }
        cout << newOst << "\n";
    }


}