#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 3e5 + 13;
//const int M = 1e5 + 13;
const int A = 213;

/*
1
5
1 2 1 2 3
*/

int a[N];
int b[N];
int d[N];
int p[N];
int p2[N];

void solve() {
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    int t = 1;
//    cin >> t;
//
//    while(t--) {
//        solve();
//    }
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    set<int> st;
    for(int i = 0; i < n - 1; i++) {
        st.insert(i);
    }

//    set<pii> q;
//    q.insert({0, n - 1});
    queue<int> q;
    q.push(n - 1);
    p[0] = -1;

    int lst = -1;
    while(!q.empty()) {
//        int v = q.begin()->s;
//        q.erase(q.end());
        int v = q.front();
        q.pop();

        int dist = d[v];

        if(p2[v + b[v]] == 0) {
            p2[v + b[v]] = v;
        }

        v += b[v];

//        cout << "while " << v << ' ' << p2[v] << ' ' << p[v] << endl;


        if(v - a[v] < 0) {
            lst = v;
            break;
        }

        while(true) {
            auto it = st.lower_bound(v);
            if(it == st.begin() || v - a[v] > *(--it))
                break;

//            cout << "go " << v << " -> " << *it << endl;

            q.push(*it);
            d[*it] = dist + 1;
            p[*it] = v;

            st.erase(it);
        }
    }

    if(lst == -1) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> res(1, -1);
    while(lst < n - 1) {
         res.push_back(p2[lst]);
         lst = p[p2[lst]];
    }

    cout << res.size() << endl;
    for(int i = res.size() - 1; i >= 0; i--)
        cout << res[i] + 1 << ' ';
    cout << endl;

}