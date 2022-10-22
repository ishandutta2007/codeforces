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

vector<pii> get(int n, vector<int> a) {
    vector<pii> a1;
    for(int i = 0; i < n; ) {
        a1.emplace_back(a[i], 0);
        int j = i;
        while(j < n && a[j] == a[i]) {
            a1.back().s++;
            j++;
        }

        i = j;
    }
    return a1;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }

    vector<pii> a1 = get(n, a), b1 = get(n, b);
//cout << "ff" << endl;
//    cout << "a1 : ";
//    for(pii p : a1)
//        cout << " (" << p.f << ", " << p.s << ") ";
//    cout << endl;
//
//    cout << "b1 : ";
//    for(pii p : b1)
//        cout << " (" << p.f << ", " << p.s << ") ";
//    cout << endl;

    vector<int> cnt(n, 0);
    for(int i = b1.size() - 1, j = a1.size() - 1; i >= 0; i--) {
//        cout << "for " << i << ' ' << j << ' ' << a1[j].f
        while(j >= 0 && a1[j].f != b1[i].f && cnt[a1[j].f] >= a1[j].s) {
//            cout << j << endl;
            cnt[a1[j].f] -= a1[j].s;
            j--;
        }

//        cout << i << ' ' << j << endl;

//        a1[j].s -= cnt[a1[j].f];
//        cnt[a1[j].f] = 0;

        if(a1[j].f != b1[i].f || a1[j].s - cnt[a1[j].f] > b1[i].s) {
            cout << "NO" << endl;
            return;
        }

        cnt[a1[j].f] += b1[i].s - a1[j].s;
        j--;
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