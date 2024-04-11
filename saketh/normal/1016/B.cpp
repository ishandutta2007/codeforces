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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T> struct kmp {
    int P;
    vector<T> word;
    vi fail;

    int adv(int cur, const T& nxt) const {
        while (cur > 0 && word[cur] != nxt)
            cur = fail[cur];
        return cur + int(word[cur] == nxt);
    }

    kmp(const vector<T>& word) : P(word.size()), word(word) {
        fail.resize(P + 1);
        for (int i = 2; i <= P; i++)
            fail[i] = adv(fail[i - 1], word[i - 1]);
    }

    vb find(const vector<T>& text) const {
        vb match(text.size());
        for (int i = 0, len = 0; i < text.size(); i++) {
            len = adv(len, text[i]);
            if (len == P) {
                match[i - len + 1] = true;
                len = fail[len];
            }
        }
        return match;
    }
};

template<typename T> struct BIT {
    int S;
    vector<T> v;

    BIT<T>(int _S) {
        S = _S;
        v.resize(S+1);
    }

    void update(int i, T k) {
        for(i++; i<=S; i+=i&-i)
            v[i] = v[i] + k;
    }

    T read(int i) {
        T sum = 0;
        for(i++; i; i-=i&-i)
            sum = sum + v[i];
        return sum;
    }

    T read(int l, int r) {
        return read(r) - read(l-1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M, Q;
    cin >> N >> M >> Q;

    vector<char> a(N), b(M);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < M; i++)
        cin >> b[i];

    kmp<char> ss(b);
    vb occ = ss.find(a);

    BIT<int> bit(N);
    for (int i = 0; i < N; i++)
        bit.update(i, occ[i]);

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r -= M;
        if (r >= l)
            cout << bit.read(l, r) << "\n";
        else
            cout << "0\n";
    }

    return 0;
}