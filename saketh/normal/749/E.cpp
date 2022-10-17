#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

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
        return read(r) - read(l-1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll N;
    cin >> N;

    double denom = N * (N + 1) / 2;

    double ans = 0;
    for (int sl = 1; sl <= N; sl++) {
        double pick = (N - sl + 1) / denom;
        double inv = .5 * sl * (sl - 1) / 2;
        ans += pick * inv;
    }

    vi val(N), loc(N);
    for (int i = 0; i < N; i++) {
        cin >> val[i];
        val[i]--;
        loc[val[i]] = i;
    }

    BIT<ll> pres(N), inx(N);
    for (int v = N - 1; v >= 0; v--) {
        ll qua = pres.read(loc[v]);
        ll sum = inx.read(loc[v]);

        double shuff = (sum + qua) * (N - loc[v]) / denom;
        ans += qua - shuff;

        pres.update(loc[v], 1);
        inx.update(loc[v], loc[v]);
    }

    cout << ans << endl;
    return 0;
}