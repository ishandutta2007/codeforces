#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 7, g = 999979;

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

struct BSGS {
    const static int p = (int)1e9 + 7;
    const static int g = 999979;
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

    int find(ll y) {
        for(int i = 0; i < m; i++) {
            int cur = (int)(1LL * V[i] * y % p);
            if(mp.count(cur)){
                return i * m + mp[cur];
            }
        }
        return -1;
    }

} bsgs;

ll n, f1, f2, f3, c;
ll l1, l2, l3, lc;

const int D = (int)6;
typedef long long ll;

struct matrix
{
    int size;
    ll a[D][D];
    void init(int _size = -1){
        if(_size != -1) size = _size;
        memset(a, 0, sizeof(a));
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
                    C.a[i][j] += a[i][k] * B.a[k][j] % (mod - 1);
                C.a[i][j] %= (mod - 1);
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
} mat;


int main() {
    cin >> n >> f1 >> f2 >> f3 >> c;
    bsgs.pre();
    l1 = bsgs.find(f1);
    l2 = bsgs.find(f2);
    l3 = bsgs.find(f3);
    lc = bsgs.find(c);

    mat.init(5);
    vector<ll> mt[5] = {
            {1, 1, 0, 0, 0},
            {0, 1, 0, 0, 0},
            {2 * lc % (mod - 1), - 6 * lc % (mod - 1), 1, 1, 1},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 1, 0}
    };
    for(int i = 0; i < 5; i++) for(int j = 0; j < 5; j++) mat.a[i][j] = mt[i][j];
    mat = mat ^ (n - 3);
    ll ln = 0;
    vector<ll> co = {4, 1, l3, l2, l1};
    for(int i = 0; i < 5; i++) ln += mat.a[2][i] * co[i] % (mod - 1);
    ln %= (mod - 1);
    ll fres = fp(g, ln);
    cout << (fres % mod + mod) % mod << endl;


}