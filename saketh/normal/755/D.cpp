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

    int N, K;
    cin >> N >> K;

    if ((N-K) < K) K = N - K;

    BIT<int> sp(N), ep(N);

    ll out = 1;
    int loc = 0;

    for (int l = 0; l < N; l++) {
        int nxt = loc + K;

        int ans = 0;
        if (nxt < N) {
            ans = sp.read(loc + 1, nxt - 1)
                + ep.read(loc + 1, nxt - 1);
        } else {
            nxt %= N;
            ans = sp.read(loc + 1, N - 1)
                + ep.read(loc + 1, N - 1)
                + sp.read(0, nxt - 1)
                + ep.read(0, nxt - 1);
        }

        out += 1 + ans;
        cout << out << " ";

        sp.update(loc, 1);
        ep.update(nxt, 1);
        loc = nxt;
    }

    cout << endl;
    return 0;
}