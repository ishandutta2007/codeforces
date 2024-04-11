#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T> struct BIT{
    int S;
    vector<T> v;

    BIT<T>(int _S){
        S = _S;
        v.resize(S+1);
    }
    
    void update(int i, T k){
        for(i++; i<=S; i+=i&-i)
            v[i] = v[i] + k;
    }

    T read(int i){
        T sum = 0;
        for(i++; i; i-=i&-i)
            sum = sum + v[i];
        return sum;
    }

    T read(int l, int r){
        r = min(r, int(v.size()));
        if (l > r) return 0;
        return read(r) - read(l-1);
    }
};

void add(int D, int O, BIT<ll> &bit, ll LIM) {
    ll cur = bit.read(D, D);
    bit.update(D, -cur);
    cur = min(cur + O, LIM);
    bit.update(D, cur);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, K, A, B, Q;
    cin >> N >> K >> B >> A >> Q;

    BIT<ll> ifa(N + 1), ifb(N + 1);

    int type, D, O, P;
    for (int i = 0; i < Q; i++) {
        cin >> type;

        if (type == 1) {
            cin >> D >> O;

            add(D, O, ifa, A);
            add(D, O, ifb, B);
        } else {
            cin >> P;

            ll ans = 0;

            ans += ifa.read(1, P - 1);
            ans += ifb.read(P + K, N);

            cout << ans << "\n";
        }
    }

    return 0;
}