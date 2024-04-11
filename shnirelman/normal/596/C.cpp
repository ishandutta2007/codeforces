//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

vector<pii> mp[N * 2];
int ind[N * 2];

//vector<vector<int>> t;
//
//int get(int i, int j) {
//    int res = 0;
//    for(int i1 = i; i1 >= 0; i1 = (i1 & (i1 + 1)) - 1) {
//        for(int j1 = j; j1 >= 0; j1 = (j1 & (j1 + 1)) - 1) {
//            res += t[i1][j1];
//        }
//    }
//    return res;
//}
//
//int upd(int i, int j, int x) {
//    for(int i1 = i; i1 < t.size(); i1 |= i1 + 1) {
//        for(int j1 = j; j1 < t[i].size(); j1 |= j1 + 1) {
//            t[i1][j1] += x;
//        }
//    }
//}



int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<pii> a(n);
//    int mxx = 0, mxy = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
//        mxx = max(mxx, a[i].f);
//        mxy = max(mxy, a[i].s);
    }

    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for(int i = 0; i < n; i++) {
        mp[a[i].s - a[i].f + N].push_back(a[i]);
    }

    for(int i = 0; i < N * 2; i++) {
        sort(mp[i].begin(), mp[i].end());
    }

    vector<pii> ord;
    for(int i = 0; i < n; i++) {
        int d = b[i] + N;
//        if(ind[d] == mp[d].size() || ind[d + 1] > ind[d]/* || ind[d] > ind[d - 1]*/) {
        if(ind[d] == mp[d].size() || (d > N && (ind[d + 1] > ind[d] || ind[d] + 1 < ind[d - 1])
                                || (d < N && (ind[d + 1] > ind[d] + 1 || ind[d - 1] > ind[d])) ||
                                      (d == N && (ind[d + 1] > ind[d] || ind[d - 1] > ind[d])))) {
//            cout << i << ' ' << b[i] << ' ' << ind[d] << ' ' << ind[d + 1] << ' ' << ind[d - 1] << endl;
            cout << "NO" << endl;
            return 0;
        }

        ord.push_back(mp[d][ind[d]++]);
    }

//    t.resize(mxx + 5, vector<int>(mxy + 5, 0));
//
//    for(auto p : ord) {
//        int s = get(mxx, mxy) + get(p.f, p.s) - get(p.f, mxy) - get(mxx, p.s);
//        if(s != 0) {
//            cout << "NO" << endl;
//            return 0;
//        }
//
//        upd(p.f, p.s, 1);
//    }

    cout << "YES" << endl;
    for(auto p : ord)
        cout << p.f << ' ' << p.s << endl;
}