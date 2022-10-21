#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50, mod = (int)1e9 + 7;

int n;
int a[N];
vector<int> dvs[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll get(ll mx, int st) {
    ll res = 1;
    int cnt = dvs[mx].size() - st, la = n;
    for(int i = st; i < dvs[mx].size(); i++) {
        int x = dvs[mx][i];
        int pt = (int)(lower_bound(a, a + n, x) - a);
        res = (res * fp(cnt, la - pt)) % mod;
        cnt--;
        la = pt;
    }
    return res;
}

ll calc(ll mx) {
    return (get(mx, 0) - get(mx, 1)) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) dvs[j].push_back(i);
    }
    for(int i = 1; i < N; i++) reverse(dvs[i].begin(), dvs[i].end());

//    cout << "ok" << endl;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    ll res = 1;
    for(int i = 2; i <= (int)1e5; i++) {
//        cout << i << ": " << calc(i) << endl;
        res += calc(i);
        res %= mod;
    }
    cout << (res % mod + mod) % mod << endl;

}