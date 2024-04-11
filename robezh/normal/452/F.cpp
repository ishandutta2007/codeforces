#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e5 + 50, INF = (int)1e9 + 50;
const int mods[4] = {(int)1e9 + 7, (int)1e9 + 9, (int)1e9 + 21, (int)1e9 + 33};
typedef pair<int, int> P;
typedef long long ll;

int add(int x, int y, int mod) {
    x += y; if(x >= mod) x -= mod;
    return x;
}

int mul(int x, int y, int mod) {
    return (int)(1LL * x * y % mod);
}

ll fp(ll x, ll k, ll mod){
    if(k == 0) return 1;
    ll hf = fp(x, k/2, mod);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}


int p = 10;
ll pw[N][4];

struct MInt {
    int x[4];
    MInt(int val = 0) {fill(x, x + 4, val);};
    void print() {
        for(int j = 0; j < 4; j++) cout << x[j] << " ";
        cout << endl;
    }
    static MInt getpw(int x) {
        MInt res;
        for(int j = 0; j < 4; j++) res.x[j] = pw[x][j];
        return res;
    }
    MInt operator + (const MInt &o) const {
        MInt res = *this;
        for(int j = 0; j < 4; j++) res.x[j] = add(x[j], o.x[j], mods[j]);
        return res;
    }
    MInt operator - (const MInt &o) const {
        MInt res = *this;
        for(int j = 0; j < 4; j++) res.x[j] = add(x[j], mods[j] - o.x[j], mods[j]);
        return res;
    }
    bool operator != (const MInt &o) const {
        for(int j = 0; j < 4; j++) if(x[j] != o.x[j]) return true;
        return false;
    }
    MInt operator * (const MInt &o) const {
        MInt res = *this;
        for(int j = 0; j < 4; j++) res.x[j] = mul(res.x[j], o.x[j], mods[j]);
        return res;
    }
    MInt operator ^ (int x) const {
        MInt res = *this;
        for(int j = 0; j < 4; j++) res.x[j] = mul(res.x[j], pw[x][j], mods[j]);
        return res;
    }
};

int n;

struct BIT {
    int n;
    MInt bit[N];


    void add(int x, MInt val) {
        for(int i = x; i < n; i |= i + 1) bit[i] = (bit[i] + val);
    }

    MInt get(int x) {
        MInt res(0);

        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res = (res + bit[i]);
        return res;
    }

} bit[2];


int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int k = 0; k < 4; k++) {
        pw[0][k] = 1;
        for(int i = 1; i < N; i++) {
            pw[i][k] = pw[i-1][k] * p % mods[k];
        }
    }
    cin >> n;
    bit[0].n = bit[1].n = n;
    for(int i = 0; i < n; i++) cin >> a[i], a[i]--;
    for(int i = 0; i < n; i++) {
        int d = min(a[i], n - 1 - a[i]);
        int l = a[i] - d, r = a[i] + d;

        MInt m1 = (bit[0].get(r) - bit[0].get(l - 1)) ^ (n - 1 - r);
        MInt m2 = (bit[1].get(r) - bit[1].get(l - 1)) ^ l;
//        cout << i << ": " << endl;
//        cout << l << " " << r << endl;
//        m1.print();
//        m2.print();
        if(m1 != m2) return cout << "YES" << endl, 0;

        bit[0].add(a[i], MInt::getpw(a[i]));
        bit[1].add(a[i], MInt::getpw(n - 1 - a[i]));
    }
    cout << "NO" << endl;
}