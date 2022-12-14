#include <bits/stdc++.h>

using namespace std;



int M, L;



typedef __int64 ll;



int MOD;



const int P = 998244353;

const int mod = P;

const int R = 3;



const double EPS = 1e-3;



int E, F, I;



int expmod(int a, int b) {

    int rlt = 1;

    while (b) {

        if (b & 1) rlt = 1ll * a * rlt % mod;

        b >>= 1;

        a = 1ll * a * a % mod;

    }

    return rlt;

}



inline ll invmod(ll a, ll p) { return expmod(a, p - 2); }



void init() {

    E = expmod(R, P >> L);

    F = invmod(E, P);

    I = invmod(M, P);

}



#define H (1 << 18)



int A[H], B[H], C[H];



void FFT(int *A, int pw) {

    for (int m = M, h; h = m >> 1, m >= 2; pw = (ll)pw * pw % mod, m = h)

        for (int i = 0, w = 1; i < h; i ++, w = (ll)w * pw % mod)

            for (int j = i; j < M; j += m) {

                int k = j + h, x = (A[j] - A[k] + mod) % mod;

                (A[j] += A[k]) %= mod;

                A[k] = (ll)w * x % mod;

            }

    for (int i = 0, j = 1; j < M - 1; j ++) {

        for (int k = M >> 1; k > (i ^= k); k >>= 1);

        if (j < i) swap(A[i], A[j]);

    }

}



void multiply(vector <int> &a, vector <int> &b, vector <int> &c) {

    int sz = a.size() + b.size() - 1;

    M = 1, L = 0;

    while (M <= sz) M <<= 1, L ++;

    init();

    memset(C, 0, M * sizeof (int));

    memset(A, 0, M * sizeof (int));

    memset(B, 0, M * sizeof (int));



    for (int i = 0; i < a.size(); i ++) A[i] = a[i];

    for (int i = 0; i < b.size(); i ++) B[i] = b[i];



    FFT(A, E);

    FFT(B, E);

    for (int i = 0; i < M; i ++) C[i] = 1ll * A[i] * B[i] % P;

    FFT(C, F);

    for (int i = 0; i < M; i ++) C[i] = 1ll * C[i] * I % P;

    c.resize(sz);

    for (int i = 0; i < sz; i ++) c[i] = C[i];//print(c);

}



#define N 101010



vector <int> v[N<<1];



priority_queue <pair <int, int> > pq;



int solve(int k, int n) {

	if (k == 0 && n == 0) return 1;

	if (k <= 0 || n <= 0) return 0;

    int e = 0;

    for (int i = 0; i < n; i ++) {

        e ++;

        v[e].push_back(i);

        v[e].push_back(1);

        pq.push(make_pair(-2, e));

    }

    int i, j;

    while (pq.size() > 1) {

        i = (pq.top()).second;

        pq.pop();

        j = (pq.top()).second;

        pq.pop();

        e ++;

        multiply(v[i], v[j], v[e]);

        pq.push(make_pair(-v[e].size(), e));

    }

    return v[e][k];

}



int zz[N], ww[N];



void prep() {

    zz[0] = 1;

    for (int i = 1; i < N; i ++) zz[i] = 1ll * zz[i-1] * i % mod;

    ww[N-1] = expmod(zz[N-1], mod - 2);

    for (int i = N - 2; i >= 0; i --) ww[i] = 1ll * ww[i+1] * (i + 1) % mod;

}



int comb(int a, int b) {

    if (b < 0 || b > a) return 0;

    if (!b || b == a) return 1;

    return 1ll * (1ll * ww[a-b] * ww[b] % mod) * zz[a] % mod;

}



double clk;



int main() {

    //freopen("r.in", "r", stdin);

    clk = clock();

    int n, a, b;

    scanf("%d %d %d", &n, &a, &b);

    if (a + b > n + 1) {

        puts("0");

        return 0;

    }

    prep();

    if (a == 1 && b == 1) {

        if (n > 1) puts("0");

        else puts("1");

        return 0;

    }

    int rlt = 1ll * comb(a + b - 2, a - 1) * solve(a + b - 2, n - 1) % mod;

    printf("%d\n", rlt);



    while (1) {

		double now = clock();

		if (now - clk > 3.4 * CLOCKS_PER_SEC) break;

    }



    return 0;

}