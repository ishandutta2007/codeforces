#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define pb push_back
const int mod = 998244353;
const int root = 15311432;
const int root_1 = 469870224;
const int root_pw = 1 << 23;
const int N = 400004;

vector<int> v[N];

ll modInv(ll a, ll mod){
    ll x0 = 0, x1 = 1, r0 = mod, r1 = a;
    while(r1){
        ll q = r0 / r1;
        x0 -= q * x1; swap(x0, x1);
        r0 -= q * r1; swap(r0, r1);
    }
    return x0 < 0 ? x0 + mod : x0;
}

void fft (vector<int> &a, bool inv) {
    int n = (int) a.size();

    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1) {
        int wlen = inv ? root_1 : root;
        for (int i=len; i<root_pw; i<<=1)
            wlen = int (wlen * 1ll * wlen % mod);
        for (int i=0; i<n; i+=len) {
            int w = 1;
            for (int j=0; j<len/2; ++j) {
                int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
                a[i+j] = u+v < mod ? u+v : u+v-mod;
                a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
                w = int (w * 1ll * wlen % mod);
            }
        }
    }

    if(inv) {
        int nrev = modInv(n, mod);
        for (int i=0; i<n; ++i)
            a[i] = int (a[i] * 1ll * nrev % mod);
    }
}

void pro(const vector<int> &a, const vector<int> &b, vector<int> &res) {
    vector<int> fa(a.begin(), a.end()),  fb(b.begin(), b.end());
    int n = 1;
    while (n < (int) max(a.size(), b.size()))  n <<= 1;
    n <<= 1;
    fa.resize (n),  fb.resize (n);

    fft(fa, false), fft (fb, false);
    for (int i = 0; i < n; ++i)
        fa[i] = 1LL * fa[i] * fb[i] % mod;
    fft (fa, true);
    res = fa;
}


int s(int n, int k) {
    int nn=1;while(nn<n) nn*=2;
    for(int i=0;i<n;i++) {
        v[i].push_back(i); v[i].push_back(1);
    }
    for(int i=n;i<nn;i++){
        v[i].push_back(1);
    }
    for (int i=nn;i>1;i>>=1) {
        int dt=i>>1;
        for(int j=0;j<dt;j++){
            //for(int k=0;k<v[j].size();k++) printf("%d ", v[j][k]); printf("\n");
            //for(int k=0;k<v[j+dt].size();k++) printf("%d ", v[j+dt][k]); printf("\n");
            pro(v[j],v[j+dt],v[j]);
            //for(int k=0;k<v[j].size();k++) printf("%d ", v[j][k]); printf("\n\n");
        }
    }
    return v[0][k];
}
int f[N], inv[N];
void init() {
    f[0]=inv[0]=1;
    for (int i=1;i<N;i++) {
        f[i]=1LL*f[i-1]*i%mod;
        inv[i]=modInv(f[i], mod);
    }
}
int c(int n, int m) {return 1LL*f[n]*inv[m]%mod*inv[n-m]%mod;}
int main() {
    init();//printf("%d\n", c(2,1));return 0;
    int n, b, f; cin >> n >> b >> f;
    //printf("%d %d\n", s(n-1,b+f-2), c(b+f-2,b-1));
    printf("%lld\n", 1LL*s(n-1,b+f-2)*c(b+f-2,b-1)%mod);
}