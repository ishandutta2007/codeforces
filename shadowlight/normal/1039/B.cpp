#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

bool query(ll l, ll r) {
    cout << l << " " << r << endl;
    string s;
    cin >> s;
    return s == "Yes";
}

int main() {
    srand(time(0));
    ll n, k;
    cin >> n >> k;
    ll l = 1, r = n;
    while (true) {
        ll mid = (l + r) / 2;
        if (r - l + 1 <= 50) {
            ll x = rand() % (r - l + 1);
            bool kek = query(l + x, l + x);
            if (kek) return 0;
            l = max(1LL, l - k);
            r = min(n, r + k);
            continue;
        }
        bool res = query(l, mid);
        if (res) {
            l = max(1LL, l - k);
            r = min(n, mid + k);
        } else {
            l = max(1LL, mid - k + 1);
            r = min(n, r + k);
        }
        //cout << l << " " << r << "\n";
    }
    query(l, r);
}