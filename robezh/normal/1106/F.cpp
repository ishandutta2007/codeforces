#include <bits/stdc++.h>
using namespace std;

const int D = (int)101, mod = (int)998244353, N = D;
typedef long long ll;


ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

struct matrix
{
    const static int mod = 998244352;
    int size;
    ll a[D][D];
    void init(int _size = -1){
        if(_size != -1) size = _size;
        memset(a, 0, sizeof(a));
    }
    matrix(){
        (*this).init(0);
    }
    matrix(int _size = -1){
        (*this).init(_size);
    }

    void set_identity(){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++) a[i][j] = (ll)(i == j);
        }
    }
    matrix operator * (const matrix &B) const
    {
        matrix C = matrix(size);

        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++){
                for(int k = 0; k < size; k++)
                    C.a[i][j] += a[i][k] * B.a[k][j] % mod;
                C.a[i][j] %= mod;
            }
        return C;
    }

    matrix operator ^ (const ll &p) const
    {
        matrix A = (*this), res = matrix(A.size);
        res.set_identity();
        ll t = p;
        while(t > 0)
        {
            if(t % 2) res = res * A;
            A = A * A;
            t /= 2;
        }
        return res;
    }
};

struct ExtGCD{
//    ll a1, b1, a2, b2, L, R;

// want to solve ax + by = gcd(a,b);
// notice: gcd(a, b) can be negative.
    ll extgcd(ll a, ll b, ll &x, ll &y) {
        ll d = a;
        if(b != 0) {
            d = extgcd(b, a % b, y, x);
            y -= (a / b) * x;
        }
        else {
            x = 1; y = 0;
        }
        return d;
    }

    ll find(ll a, ll b, ll res) {
        ll x, y;
        ll g = extgcd(a, b, x, y);
        if(res % g != 0) return -1;
        return x * (res / g);
    }
};

struct BSGS {
    const static int p = 998244353;
    const static int g = 3;
    int m;
    map<int, int> mp;
    vector<int> V;

    void pre() {
        m = (int)ceil(sqrt(p + 0.0) + 1);
        int cg = 1, revgm = 1;
        int invm = (int)(fp(fp(g, m), p - 2));
        for(int i = 0; i < m; i++)  {
            mp[cg] = i;
            V.push_back(revgm);
            cg = (int)(1LL * cg * g % p);
            revgm = (int)(1LL * revgm * invm % p);
        }
    }

    int find(int y) {
        for(int i = 0; i < m; i++) {
            int cur = (int)(1LL * V[i] * y % p);
            if(mp.count(cur)){
                return i * m + mp[cur];
            }
        }
        return -1;
    }

};

int k;
ll b[N];
int n, x;

int main() {
    cin >> k;
    for(int i = 0; i < k; i++) cin >> b[i];
    cin >> n >> x;

    matrix mt = matrix(k);
    for(int i = 0; i < k; i++) mt.a[0][i] = b[i];
    for(int i = 1; i < k; i++) mt.a[i][i-1] = 1;

    mt = mt ^ (n - k);

    ll c = mt.a[0][0];
    BSGS bsgs;
    bsgs.pre();
    int hn = bsgs.find(x);
//    cout << hn<< endl;

    ExtGCD gcd;

    ll hk = gcd.find(c, mod-1, hn);
    if(hk == -1) return !printf("-1");
    hk = (hk % (mod - 1) + (mod - 1)) % (mod - 1);

    assert(1LL * c * hk % (mod - 1) == 1LL * hn % (mod - 1));
    ll res = fp(3, hk);
    cout << res << endl;
}