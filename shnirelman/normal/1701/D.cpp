#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
const int N = 5000 + 13;
const int LOGN = 30;
const int L = 2001;

void solve() {
    int n;
    cin >> n;

    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pii> seg(n);
    for(int i = 0; i < n; i++) {
        {
            int l = 0, r = n + 1;
            while(r - l > 1) {
                int m = (l + r) / 2;
//                cout << " bin search " << l << ' ' << m << ' ' << r << ' ' << (i + 1) / m << endl;
                if((i + 1) / m <= b[i])
                    r = m;
                else
                    l = m;
            }

            seg[i].f = r;
        }

        {
            int l = 1, r = n + 1;
            while(r - l > 1) {
                int m = (l + r) / 2;
                if((i + 1) / m < b[i])
                    r = m;
                else
                    l = m;
            }

            seg[i].s = l;
        }

//        cout << i << ' ' << seg[i].f << ' ' << seg[i].s << endl;
    }

    vector<pair<pii, int>> ord(n);
    for(int i = 0; i < n; i++) {
        ord[i] = {seg[i], i};
    }

    sort(ord.begin(), ord.end());

    vector<int> a(n, -1);
    set<pii> st;
    for(int i = 1, j = 0; i <= n; i++) {
//        cout << "i = " << i << endl;
        while(j < n && ord[j].f.f == i) {
//            cout << "   j = " << j << endl;
            st.emplace(ord[j].f.s, ord[j].s);
            j++;
        }

//        cout << "st.size() = " << st.size() << endl;

        int pos = st.begin()->s;
        a[pos] = i;
        st.erase(st.begin());
    }

    for(int x : a)
        cout << x << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);



//    int sum = 0;
//    for(int i = 1; i <= n; i++) {
////        cout << i / (n - i + 1) << ' ';
//        sum += i / (n - i + 1);
//    }
//
//    cout << endl << sum << endl;

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}