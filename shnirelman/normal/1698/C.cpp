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
const int N = 2e5 + 13;
const int LOGN = 30;

void solve() {
    int n;
    cin >> n;

    vector<int> a;
    bool fl = false;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if(x != 0 || !fl)
            a.push_back(x);

        fl |= (x == 0);
    }

    sort(a.begin(), a.end());

    if(a.size() < 3) {
        cout << "YES" << endl;
        return;
    }

    if(a[0] + a[1] + a[2] < a[0] || a[a.size() - 1] + a[a.size() - 2] + a[a.size() - 3] > a.back()) {
        cout << "NO" << endl;
        return;
    }

    set<int> st(a.begin(), a.end());

    for(int i = 0; i < a.size(); i++) {
        for(int j = i + 1; j < a.size(); j++) {
            for(int k = j + 1; k < a.size(); k++) {
                if(st.count(a[i] + a[j] + a[k]) == 0) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}