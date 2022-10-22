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

bool is(vector<int> a, vector<int> b) {
    int cnt = 0;
    for(int i = 0; i < 5; i++)
        cnt += (a[i] < b[i]);
    return (cnt >= 3);
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(5));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }

    int cur = 0;
    for(int i = 1; i < n; i++) {
        if(is(a[i], a[cur]))
            cur = i;
    }

    bool res = true;
    for(int i = 0; i < n; i++) {
        if(i != cur && is(a[i], a[cur])) {
            res = false;
        }
    }

    cout << (res ? cur + 1 : -1) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}