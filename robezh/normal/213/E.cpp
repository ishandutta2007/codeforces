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
    bool operator == (const MInt &o) const {
        for(int j = 0; j < 4; j++) if(x[j] != o.x[j]) return false;
        return true;
    }
    MInt operator * (const MInt &o) const {
        MInt res = *this;
        for(int j = 0; j < 4; j++) res.x[j] = mul(res.x[j], o.x[j], mods[j]);
        return res;
    }
    MInt operator * (const int o) const {
        MInt res = *this;
        for(int j = 0; j < 4; j++) res.x[j] = mul(res.x[j], o, mods[j]);
        return res;
    }
    MInt operator ^ (int x) const {
        MInt res = *this;
        for(int j = 0; j < 4; j++) res.x[j] = mul(res.x[j], pw[x][j], mods[j]);
        return res;
    }
};


struct BIT {
    int n;
    MInt bit[N];
    int v[N];


    void addM(int x, MInt val) {
        for(int i = x; i < n; i |= i + 1) bit[i] = (bit[i] + val);
    }
    void addv(int x, int val) {
        for(int i = x; i < n; i |= i + 1) v[i] = (v[i] + val);
    }

    MInt getM(int x) {
        MInt res(0);

        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res = (res + bit[i]);
        return res;
    }
    int getv(int x) {
        int res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res = (res + v[i]);
        return res;
    }

} bit;

int n, m;
MInt A, B;
int a[N], b[N];



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int k = 0; k < 4; k++) {
        pw[0][k] = 1;
        for(int i = 1; i < N; i++) {
            pw[i][k] = pw[i-1][k] * p % mods[k];
        }
    }

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; x--;
        a[x] = i;
        A = (A + MInt::getpw(x) * (n - 1 - i));
    }
    for(int i = 0; i < m; i++) {
        int x; cin >> x; x--;
        b[x] = i;
    }
    bit.n = m;
    int res = 0;
    for(int i = 0; i < m; i++) {
        bit.addM(b[i], MInt::getpw(i));
        bit.addv(b[i], 1);
        B = (B + MInt::getpw(i) * (min(i + 1, n) - bit.getv(b[i])));
        B = (B + bit.getM(b[i] - 1));


//        bit.getM(b[i] - 1).print();
//        cout << "back: " << n - bit.getv(b[i]) << endl;
        if(i < n - 1) continue;
//        cout << i << ": ";
//        A.print();
//        B.print();


        if((A ^ (i - (n - 1))) == B) res++;

        int la = i - (n - 1);
        B = (B - MInt::getpw(la) * (min(n, i + 1) - bit.getv(b[la])));
        B = (B - bit.getM(b[la] - 1));
        bit.addM(b[la], MInt(0) - MInt::getpw(la));
        bit.addv(b[la], -1);
    }
    cout << res << endl;



}