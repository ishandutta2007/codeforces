#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (int)1e5 + 50;
ll n, m, k;
ll a[N];
int cur = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) cin >> a[i];
    ll res = 0;
    while(cur < m) {
        res++;
        ll cur_i = a[cur] - cur;
        ll next_cur = (cur_i % k == 0 ? cur_i : cur_i - cur_i % k + k) + cur;
        while(cur < m && a[cur] <= next_cur) cur++;
    }
    cout << res << endl;
}