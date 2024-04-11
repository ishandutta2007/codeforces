#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int INF = 1e9;
const int N = 2e5 + 13;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    bool ans = true;

    vector<bool> b(n, false);
    vector<int> rg(n, n), lf(n, -1);
//    for(int i = 0; i < n; i++) {
//        if(a[i] == 0) {
//            b[i] = true;
//
//        }
//    }

    for(int i = 0; i < n - 1; i++) {
        if(!b[i + 1])
            rg[i] = i + 1;
        else
            rg[i] = i + 2;
    }
    for(int i = 1; i < n; i++) {
        if(!b[i - 1])
            lf[i] = i - 1;
        else
            lf[i] = i - 2;
    }

    vector<int> cnt(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cnt[i]++;
    }

    set<pair<int, pii>> st;
    for(int i = 0; i < n; i++) {
        st.insert({-cnt[i], {a[i], i}});
    }

    int cur = 0;
    while(!st.empty()) {
        int ind = st.begin()->s.s;
        st.erase(st.begin());

//        cout << "dfges" << endl;
//        for(auto p : st) {
//            cout << p.f << ' ' << p.s.f << ' ' << p.s.s << endl;
//        }


        if(a[ind] != cur) {
            cout << "No" << endl;
            return;
        }

        if(lf[ind] >= 0) {
            rg[lf[ind]] = rg[ind];
        }

        if(rg[ind] < n) {
            st.erase({-cnt[rg[ind]], {a[rg[ind]], rg[ind]}});
            cnt[rg[ind]] += cnt[ind];
            st.insert({-cnt[rg[ind]], {a[rg[ind]], rg[ind]}});
            lf[rg[ind]] = lf[ind];
        }

        cur++;
    }


    cout << "Yes" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}