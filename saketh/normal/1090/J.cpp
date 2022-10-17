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

    int adv(int len, const T& nxt) const {
        while (len > 0 && word[len] != nxt)
            len = fail[len];
        return len + int(word[len] == nxt);
    }

    /*
     * Initializes the "failure table" for the search word.
     * For i > 0, fail[i] is the length of the longest proper
     * suffix of word[0, i) that is a prefix of word.
     */
    kmp(const vector<T>& word) : P(word.size()), word(word) {
        fail.resize(P + 1);
        for (int i = 2; i <= P; i++)
            fail[i] = adv(fail[i - 1], word[i - 1]);
    }

    /*
     * Finds all occurences of the search word in the given text.
     * match[i] indicates whether there exists a match starting at
     * index i of text.
     */
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

/*
 * Returns the vector z such that z[i] = the greatest length l
 * such that s[i, i+l) matches the prefix s[0, l).
 */
template<typename T> vi z_algorithm(const vector<T>& s) {
    int N = s.size();
    vi z(N);
    z[0] = N;

    for (int i = 1, l, r = -1; i < N; i++) {
        z[i] = r > i ? min(r - i, z[i - l]) : 0;
        while (i + z[i] < N && s[i + z[i]] == s[z[i]])
            z[i]++;
        if (i + z[i] > r)
            l = i, r = i + z[i];
    }
    return z;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string s, t;
    cin >> s >> t;
    string ts = t + "|" + s;

    vector<char> tv(all(t));
    kmp k(tv);

    vector<char> tsv(all(ts));
    vi z = z_algorithm(tsv);

    vi match(t.size() + 1);
    for (int i = 1; i < s.size(); i++)
        match[z[t.size() + 1 + i]]++;

    for (int l = t.size() - 1; l >= 0; l--) {
        match[l] += match[l+1];
    }

    ll ans = 0;
    for (int l = 1; l <= t.size(); l++) {
        ans += s.size();
        if (k.fail[l] > 0) {
            ans -= match[l - k.fail[l]];
        }
    }
    cout << ans << endl;

    return 0;
}