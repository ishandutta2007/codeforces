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
const int N = 1e6 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

int solve(int n, int k, vector<pair<pii, int>> a, bool fl, int x) {
    set<pii> st;
    int res = 0;
    for(int i = 0; i < n; i++) {
        st.insert({a[i].f.s, a[i].s});
        if(st.size() > k)
            st.erase(st.begin());
        if(st.size() == k) {
            res = max(res, st.begin()->f - a[i].f.f);
            if(fl && res == x) {
                cout << res << endl;
                for(auto p : st)
                    cout << p.s + 1 << ' ';
                exit(0);
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<pii, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].f.f >> a[i].f.s;

        a[i].f.f--;
        a[i].s = i;
    }

    sort(a.begin(), a.end());

    solve(n, k, a, true, solve(n, k, a, false, 0));

}