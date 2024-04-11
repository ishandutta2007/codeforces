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

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

double dist(pi l, pi r);

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

int n, m;


void add(set<pair<int, int>>&se, pair<int, int> list) {
    if(list.first >= 0 && list.first <= n && list.second >= 0 && list.second <= m) {
        se.insert(list);
    }
}


void solve(){
    cin >> n >> m;
    set<pair<int, int>> intr;
    for(int i = 0; i <= 2; ++i) {
        for(int j = 0; j <= 2; ++j) {
            add(intr, {i, j});
            add(intr, {n - i, j});
            add(intr, {n - i, m - j});
            add(intr, {i, m - j});
        }
    }
    vector<pi> x;
    for(const pi& a: intr) {
        x.push_back(a);
    }

    double best = 0;
    vector<pi> bestp;
    for(pi& a: x)
        for(pi& b: x) {
            if(a == b)
                continue;
            for(pi& c: x) {
                if(a == c || b == c)
                    continue;
                for (pi& d: x) {
                    if(a == d || b == d | c == d)
                        continue;

                    double len = dist(a, b) + dist(b, c) + dist(c, d);

                    if(len > best) {
                        best = len;
                        bestp = {a, b, c, d};
                    }

                }
            }
        }

    for(const pi& xx: bestp) {
        cout << xx.first << ' '<<xx.second << "\n";
    }
}

double sqr(int a) {
    return a * a;
}

double dist(pi l, pi r) {
    return sqrt(sqr(l.first - r.first) + sqr(l.second - r.second));
}