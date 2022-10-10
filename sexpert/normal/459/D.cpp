#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

map<int, int> cnt;
const int MAXN = 1e6 + 10;
int BIT[MAXN];

void upd(int p, int v) {
    for(; p < MAXN; p += (p & -p))
        BIT[p] += v;
}

ll sum(int p) {
    ll res = 0;
    for(;p > 0; p -= (p & -p))
        res += BIT[p];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n), arr(n);
    for(auto &x : v)
        cin >> x;
    ll res = 0;
    for(int i = 0; i < n; i++) {
        cnt[v[i]]++;
        arr[i] = cnt[v[i]];
    }
    cnt.clear();
    for(int i = n - 2; i >= 0; i--) {
        cnt[v[i + 1]]++;
        upd(cnt[v[i + 1]], 1);
        res += sum(arr[i] - 1);
    }
    cout << res << endl;
}