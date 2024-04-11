#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e7 + 13;
//const int M = 1e5 + 13;
const int A = 26;

/*
1
5
1 2 1 2 3
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        mp[a[i]].push_back(i);
    }

    vector<int> b(n, -INF);

    int s = 0;
    int cnt = 0;
    for(auto p : mp) {
        for(int i = 1; i < p.s.size(); i += 2) {
            b[p.s[i]] = -1;
            b[p.s[i - 1]] = 1;
            cnt += 2;
        }
    }

    if(cnt == n - 1) {
        for(auto p : mp) {
            if(p.s.size() > 1) {
                b[p.s[0]] = -INF;
                b[p.s[1]] = -INF;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(b[i] == -INF) {
            s += a[i];
        }
    }

    int ind = -1;
    for(int i = 0; i < n; i++) {
        if(b[i] == -INF && s != a[i])
            ind = i;
    }



//    cout << s << ' ' << ind << endl;

    if(ind != -1) {
        b[ind] = s - a[ind];
        for(int i = 0; i < n; i++) {
            if(b[i] == -INF)
                b[i] = -a[ind];
        }
    }

    for(auto x : b)
        cout << x << ' ';
    cout << endl;
}

signed main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}