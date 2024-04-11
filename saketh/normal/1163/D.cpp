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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string code, good, bad;
    cin >> code >> good >> bad;

    vector<char> good_vec, bad_vec;
    for (char c : good) good_vec.push_back(c);
    for (char c : bad) bad_vec.push_back(c);
    kmp gk(good_vec), bk(bad_vec);

    int G = good.size(), B = bad.size();

    vi dp(G * B, INT_MIN);
    dp[0] = 0;

    for (char c : code) {
        vi nxt(G * B, INT_MIN);

        char c0, c1;
        if (c == '*') {
            c0 = 'a';
            c1 = 'z';
        } else {
            c0 = c1 = c;
        }

        for (int g = 0; g < G; g++) {
            for (int b = 0; b < B; b++) {
                if (dp[g * B + b] == INT_MIN) continue;
                for (char c = c0; c <= c1; c++) {
                    int gg = gk.adv(g, c),
                        bb = bk.adv(b, c);
                    int vv = dp[g * B + b];
                    if (gg == G) {
                        vv++;
                        gg = gk.fail[gg];
                    }
                    if (bb == B) {
                        vv--;
                        bb = bk.fail[bb];
                    }
                    nxt[gg * B + bb] = max(nxt[gg * B + bb], vv);
                }
            }
        }

        dp = nxt;
    }

    int ans = INT_MIN;
    for (int v : dp)
        ans = max(ans, v);
    cout << ans << endl;

    return 0;
}