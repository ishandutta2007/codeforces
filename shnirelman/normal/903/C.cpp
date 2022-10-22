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

     int n;
     cin >> n;

    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        mp[x]++;
    }

    int mx = 0;
    for(auto p : mp) {
        mx = max(mx, p.s);
    }

    cout << mx << endl;
}