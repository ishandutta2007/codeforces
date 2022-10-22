//#define _GLIBCXX_DEBUG
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

mt19937 rnd(36547);

/*
1
7
6 4 6 2 4 5 6
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), x(n);
//    vector<vector<int>> r(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;

//        r[a[i]].push_back(i);
        x[a[i]]++;
    }

    vector<bool> used(n, false);
//    set<pii> st;
//    for(int i = 0; i < n; i++) {
//        st.insert({});
//    }

    vector<int> b(n, -1);
    int ans = 0;

//    vector<int> c;
    set<int> st;
    for(int i = 0; i < n; i++) {
        if(x[i] == 0) {
            if(used[a[i]]) {
//                c.push_back(i);
            } else {
                b[i] = a[i];
                used[a[i]] = true;
                ans++;
            }
//            st.insert(i);
        }
    }


    for(int i = 0; i < n; i++) {
        if(b[i] == -1 && !used[a[i]]) {
            ans++;
            b[i] = a[i];
            used[a[i]] = true;
        }
    }

    vector<int> d, c;
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            st.insert(i);
            c.push_back(i);
        }
        if(b[i] == -1) {
            d.push_back(i);
        }
    }

    for(int i = 0; i < d.size(); i++) {
        if(c[i] == d[i]) {
            if(i > 0)
                swap(d[i], d[i - 1]);
            else
                swap(d[i], d[i + 1]);
        }
    }

//    for(auto x : st)
//        cout << x << ' ';
//    cout << endl;

    for(int i = 0; i < d.size(); i++) {
        b[d[i]] = c[i];
    }
//    for(int i = n - 1; i >= 0; i--) {
//
//        if(b[i] == -1) {
////            cout << "i " << i << endl;
//            auto it = st.begin();
//            if(*it == i)
//                it++;
//
//            b[i] = *it;
//            st.erase(it);
//        }
//    }
//return;
    ans = 0;
    for(int i = 0; i < n; i++)
        ans += (a[i] == b[i]);

    cout << ans << '\n';
    for(int i = 0; i < n; i++) {
        cout << b[i] + 1 << ' ';
    }
    cout << '\n';
//    cout << endl;


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}