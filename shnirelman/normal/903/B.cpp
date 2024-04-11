#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;

mt19937 rnd(36547);

/*

*/


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h1, a1, c, h2, a2;
    cin >> h1 >> a1 >> c >> h2 >> a2;

    vector<bool> res;
    while(h2 > 0) {
        if(h1 > a2 || h2 <= a1) {
            res.push_back(true);
            h2 -= a1;
        } else {
            res.push_back(false);
            h1 += c;
        }

        h1 -= a2;
    }

    cout << res.size() << endl;
    for(auto x : res)
        cout << (x ? "STRIKE" : "HEAL") << endl;
}