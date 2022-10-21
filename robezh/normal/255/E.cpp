#include <bits/stdc++.h>
using namespace std;

const int N = 881918, K = 881918;
typedef long long ll;

int f[N];
ll num[N];
int sg[N];
int n;

struct BIT {
    int bit[N];

    void add(int x, int val) {
        for(int i = x; i < N; i |= i + 1) bit[i] += val;
    }

    int get(int x) {
        int res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }

    int get(int l, int r) {
        if(l > r) return 0;
        return get(r) - get(l - 1);
    }
} bit[4];

ll pw(ll x, int p) {
    if(p == 2) return 1LL * x * x;
    else return 1LL * x * x * x * x;
}

int sqrt_k(ll x, int k) {
    int l = 0, r = (int)min(x - 1, 1LL * (k == 4 ? 950 : 900000)), mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        bool flag;
        if(k == 2) flag = pw(mid, k) > x;
        else flag = pw(mid, k) >= x;
        if(flag) r = mid;
        else l = mid;
    }
    return r;
}

int get_sg(ll i) {
    int l = sqrt_k(i, 4), r = sqrt_k(i, 2) - 1;
    for(int k = 0; k < 4; k++) if(bit[k].get(l, r) == 0) return k;
    return 4;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int mx = 0;
    for(int i = 0; i < N; i++) {
        f[i] = get_sg(i);
        bit[f[i]].add(i, 1);
    }
    cin >> n;
    int xorsum = 0;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        sg[i] = num[i] < N ? f[num[i]] : get_sg(num[i]);
        xorsum ^= sg[i];
    }
    if(xorsum == 0) cout << "Rublo" << endl;
    else cout << "Furlo" << endl;

}