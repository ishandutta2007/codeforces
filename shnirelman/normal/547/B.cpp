#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 1e5 + 13;

/*
*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }

    multiset<int> len;
    len.insert(n);
    set<pii> st;
    st.insert({0, n});

    map<int, int> res;
    for(auto p : mp) {
        {
            auto it = len.end();
            res[p.f] =  *(--it);
//            cout << "res " << p.f << ' ' << res[p.f] << endl;
//            for(auto x : len)
//                cout << x << ' ';
//            cout << endl;
//            for(auto pp : st)
//                cout << pp.f << ' ' << pp.s <<endl;
        }

        for(int i : p.s) {
            auto it = st.upper_bound(make_pair(i, INF));
            it--;
            int l = it->f, r = it->s;
            st.erase(it);
            len.erase(len.find(r - l));

//            cout << "del " << i << ' ' << l << ' ' << r << endl;

            st.insert({l, i});
            len.insert(i - l);

            st.insert({i + 1, r});
            len.insert(r - i - 1);
        }

    }

    vector<int> ans(n, 0);
    auto it = res.end();
    it--;
    for(int i = 1; i <= n; i++) {
        while(it->s < i)
            it--;
        ans[i - 1] = it->f;
    }

    for(auto x : ans)
        cout << x << ' ';
}