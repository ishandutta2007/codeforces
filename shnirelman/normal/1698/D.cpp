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

//vector<int> A = {4, 2, 5, 1, 3};
vector<int> A = {1, 3, 2};

//vector<int> query(int l, int r) {
//    cout << "? " << l + 1 << ' ' << r << endl;
//
//    vector<int> a(r - l);
//    for(int i = 0; i < r - l; i++)
//        a[i] = A[l + i];
//
//    sort(a.begin(), a.end());
//
//    return a;
//}

vector<int> query(int l, int r) {
    cout << "? " << l + 1 << ' ' << r << endl;

    vector<int> a(r - l);
    for(int i = 0; i < r - l; i++)
        cin >> a[i];

    return a;
}

void answer(int i) {
    cout << "! " << i + 1 << endl;
}

void solve() {
    int n;
    cin >> n;

    int l = 0, r = n - 1;
    while(r - l > 0) {
        int m = (l + r) / 2;

        auto a = query(l, m + 1);
        int cnt = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] > l && a[i] <= m + 1) {
                cnt++;
            }
        }

//        cout << "l m r " << l << ' ' << m << ' ' << r << ' ' << cnt << endl;

        if(cnt % 2 == 0)
            l = m + 1;
        else
            r = m;
    }

    answer(l);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}