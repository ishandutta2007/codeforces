#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
//const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

int p[N], sz[N];

int get(int x) {
    return (p[x] == x ? x : p[x] = get(p[x]));
}

void unite(int x, int y) {
    x = get(x);
    y = get(y);

    if(x == y)
        return;

    if(sz[x] < sz[y])
        swap(x, y);

    p[y] = x;
    sz[x] += sz[y];
}

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
    }

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    {
        stack<int> st;
//        int mn = n - 1;
        for(int i = n - 1; i >= 0; i--) {
            int fir = -1;
            while(!st.empty() && a[st.top()] < a[i]) {
                unite(i, st.top());
                if(fir == -1)
                    fir = st.top();
                st.pop();
            }
//
//            stack<int> st1 = st;
//            cout << "for " << i << " : ";
//            while(!st1.empty()) {
//                cout << "(" << st1.top() << ' ' << a[st1.top()] << ") ";
//                st1.pop();
//            }
//            cout << endl;

//            if(a[i] > a[mn])
//                unite(i, mn);
//            else
//                mn = i;

//            cout << "for " << i << ' ' << mn << endl;

            st.push(i);
            if(fir != -1)
                st.push(fir);

//            st1 = st;
//            cout << "for " << i << " : ";
//            while(!st1.empty()) {
//                cout << "(" << st1.top() << ' ' << a[st1.top()] << ") ";
//                st1.pop();
//            }
//            cout << endl;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += (p[i] == i);

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}