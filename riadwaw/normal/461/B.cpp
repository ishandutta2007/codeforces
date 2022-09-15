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

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();


#define FILENAME "souvenir"

int main(){
    string s = FILENAME;
#ifdef DEBUG
    freopen("/Users/RiaD/Contests/Contests/input", "r", stdin);
    //freopen("output", "w", stdout);
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
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
#ifdef DEBUG
    cerr<<"\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
    return 0;
}

vector<int> children[101010];
int color[101010];
li dp[2][101010];

const int mod = 1000000007;

void go(int v) {
    li cur[2] = {0, 0};
    cur[color[v]] += 1;
    for(int to: children[v]) {
        go(to);
    }


    for(int to: children[v]) {

        cur[1] = cur[1] * (dp[0][to] + dp[1][to]) + cur[0] * dp[1][to];
        cur[0] = cur[0] * (dp[0][to] + dp[1][to]);
        cur[0] %= mod;
        cur[1] %= mod;
    }

    dp[0][v] = cur[0];
    dp[1][v] = cur[1];

}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int a;
        cin >> a;
        children[a].push_back(i);
    }

    for(int i = 0; i < n; ++i) {
        cin >> color[i];
    }


    go(0);


    cout << ( dp[1][0]) % mod;
}