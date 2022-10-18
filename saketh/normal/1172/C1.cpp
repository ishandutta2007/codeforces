#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

template<int MOD> struct modnum {
    int v;
    modnum() : v(0) {}
    modnum(ll _v) : v(_v % MOD) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend istream& operator >> (istream& i, modnum& n) { ll v; i >> v; n = modnum(v); return i; }
    friend ostream& operator << (ostream& o, const modnum& n) { return o << n.v; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum& o) { v = int(ll(v) * ll(o.v) % MOD); return *this; }
    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }

    modnum pow(int e) const {
        if (e == 0) return 1;
        if (e & 1) return *this * this->pow(e-1);
        return (*this * *this).pow(e/2);
    }

    modnum inv() const {
        int g = MOD, x = 0, y = 1;
        for (int r = v; r != 0; ) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        assert(g == 1);
        assert(y == MOD || y == -MOD);
        return x < 0 ? x + MOD : x;
    }
    modnum& operator /= (const modnum& o) { return (*this) *= o.inv(); }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }

    static modnum fact(int n) {
        static vector<modnum<MOD>> fact = { 1 };
        while (fact.size() <= n)
            fact.push_back(fact.back() * fact.size());
        return fact[n];
    }
    static modnum ncr(int n, int r) {
        if (r < 0 || n < r) return 0;
        return fact(n) / (fact(r) * fact(n - r));
    }
};
using mn = modnum<998244353>;
using vmn = vector<mn>;
using vvmn = vector<vmn>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    vi like(N);
    for (int i = 0; i < N; i++) {
        cin >> like[i];
    }

    vmn weight(N);
    mn totLike = 0, totHate = 0;
    for (int i = 0; i < N; i++) {
        cin >> weight[i];
        (like[i] ? totLike : totHate) += weight[i];
    }

    // liked[v][l] = pr of liking l of the first v pictures
    vvmn liked(M + 1, vmn(M + 1));
    liked[0][0] = 1;

    for (int v = 0; v < M; v++) {
        for (int l = 0; l <= v; l++) {
            if (liked[v][l].v == 0) continue;

            mn likeWeight = totLike + l;
            mn hateWeight = totHate - (v - l);

            mn prLike = likeWeight / (likeWeight + hateWeight);
            liked[v+1][l+1] += liked[v][l] * prLike;
            liked[v+1][l] += liked[v][l] * (1 - prLike);
        }
    }

    for (int i = 0; i < N; i++) {
        // visit[v][l] = pr of visiting this l times out of v visits to its group
        vvmn visit(M + 1, vmn(M + 1));
        visit[0][0] = 1;

        for (int v = 0; v < M && (like[i] || v < totHate.v); v++) {
            for (int l = 0; l <= v; l++) {
                if (visit[v][l].v == 0) continue;

                mn myWeight = weight[i] + (like[i] ? l : -l);
                mn totalWeight = like[i] ? totLike + v : totHate - v;
                assert(totalWeight.v != 0);

                visit[v+1][l+1] += visit[v][l] * myWeight / totalWeight;
                visit[v+1][l] += visit[v][l] * (totalWeight - myWeight) / totalWeight;
            }
        }

        mn ans = weight[i];
        for (int gv = 0; gv <= M; gv++) {
            for (int mv = 0; mv <= gv; mv++) {
                ans += (like[i] ? liked[M][gv] : liked[M][M-gv]) * visit[gv][mv] * (like[i] ? mv : -mv);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}