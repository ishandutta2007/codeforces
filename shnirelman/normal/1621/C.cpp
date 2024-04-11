#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
*/

int query(int i) {
    cout << "? " << i + 1 << endl;
    int res;
    cin >> res;

    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> p(n, -1);
    for(int i = 0; i < n; i++) {
        if(p[i] == -1) {
            set<int> st;
            vector<int> ord;
            while(true) {
                int res = query(i);
                if(st.count(res))
                    break;

                st.insert(res);
                ord.push_back(res);
            }

            int j;
            for(j = 0; j < ord.size(); j++) {
                if(ord[j] == i + 1)
                    break;
            }

            int lst = ord[(j == ord.size() - 1 ? 0 : j + 1)];
            for(int k = j; ; k = (k == 0 ? ord.size() - 1 : k - 1)) {
                if(p[ord[k] - 1] != -1)
                    break;
                p[ord[k] - 1] = lst;
                lst = ord[k];

            }
        }
    }

    cout << "! ";
    for(int i = 0; i < n; i++)
        cout << p[i] << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}