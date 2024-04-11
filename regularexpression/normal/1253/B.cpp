#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

typedef long long ll;
typedef long double ld;

//#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> days;
    vector<int> day(n);
    set<int> cl, op;
    int cnt = 0, cur = -1;
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cur++;
            days.pb({});
            cl.clear();
            op.clear();
        }
        day[i] = cur;
        days.back().pb(a[i]);
        if (a[i] < 0) {
            if (op.find(-a[i]) == op.end()) {
                cout << "-1\n";
                return 0;
            }
            op.erase(-a[i]);
            cl.insert(-a[i]);
            cnt--;
        } else {
            if (op.find(a[i]) != op.end() || cl.find(a[i]) != cl.end()) {
                cout << "-1\n";
                return 0;
            }
            op.insert(a[i]);
            cnt++;
        }
    }
    if (!op.empty()) {
        cout << "-1\n";
        return 0;
    }
    cout << sz(days) << '\n';
    for (auto d : days) {
        cout << sz(d) << " ";
    }
    return 0;
}