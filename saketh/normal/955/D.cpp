#include <bits/stdc++.h>
using namespace std;

// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define resz resize

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; })

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
        re(first); re(rest...);
    }

    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.f,", ",x.s,"}");
    }
    template<class T, bool pretty = true> void prContain(const T& x) {
        if (pretty) pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;
        if (pretty) pr("}");
    }
    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps();
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...);
    }
}
using namespace __output;

#define TRACE(x) x
#define __pn(x) pr(#x, " = ")
#define pd(...) __pn((__VA_ARGS__)), ps(__VA_ARGS__), cout << flush

namespace __algorithm {
    template<typename T> void dedup(vector<T>& v) {
        sort(all(v)); v.erase(unique(all(v)), v.end());
    }
    template<typename T> typename vector<T>::const_iterator find(const vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(const vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }

    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator lower_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return lower_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator upper_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return upper_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
}
using namespace __algorithm;

struct __monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))__monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))__monostate& ms) { return os; }
} ms;

namespace __io {
    FILE* setIn(string s) { return freopen(s.c_str(),"r",stdin); }
    FILE* setOut(string s) { return freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

// trie {{{
template<int MIN_CHAR, int SIGMA>
struct trie {
    struct node {
        int depth;
        array<int, SIGMA> child_links;

        int dict_index = -1;

        int suffix_link = 0;
        int dict_suffix_link = 0;
        int count_suffixes_in_dict = 0;

        node(int depth_) : depth(depth_) {
            child_links.fill(0);
        }
    };

    vector<node> data;
    vector<int> dictionary_word_links;

    int& child_link(int loc, int c) { return data[loc].child_links[c - MIN_CHAR]; }
    int child_link(int loc, int c) const { return data[loc].child_links[c - MIN_CHAR]; }

    int dict_proper_suffix_link(int loc) const {
        return data[data[loc].suffix_link].dict_suffix_link;
    }

    trie() {}

    template<typename I>
    trie(I begin, I end) : data(1, node(0)) {
        for (I iter = begin; iter != end; iter++)
            __add_dictionary_word(*iter);
        __build_suffix_link_tree();
    }

    template<typename S>
    void __add_dictionary_word(const S& s) {
        int loc = 0;
        for (auto c_ : s) {
            int c = c_;
            assert(MIN_CHAR <= c && c < MIN_CHAR + SIGMA);
            if (!child_link(loc, c)) {
                child_link(loc, c) = int(data.size());
                data.push_back(node(data[loc].depth + 1));
            }
            loc = child_link(loc, c);
        }
        if (data[loc].count_suffixes_in_dict == 0) {
            data[loc].dict_suffix_link = loc;
            data[loc].dict_index = int(dictionary_word_links.size());
        }
        data[loc].count_suffixes_in_dict++;
        dictionary_word_links.push_back(loc);
    }

    vector<vector<int>> children;
    vector<pair<int, int>> dfs_ranges;
    void __build_suffix_link_tree() {
        children.resize(data.size());

        queue<int> bfs;
        for (int child : data[0].child_links)
            if (child) bfs.push(child);
        for (; !bfs.empty(); bfs.pop()) {
            int loc = bfs.front();
            int parent = data[loc].suffix_link;

            children[parent].push_back(loc);
            if (data[loc].dict_suffix_link == 0)
                data[loc].dict_suffix_link = data[parent].dict_suffix_link;
            data[loc].count_suffixes_in_dict += data[parent].count_suffixes_in_dict;

            for (int c = MIN_CHAR; c < MIN_CHAR + SIGMA; c++) {
                int &trie_child = child_link(loc, c);
                if (trie_child) {
                    bfs.push(trie_child);
                    data[trie_child].suffix_link = child_link(parent, c);
                } else trie_child = child_link(parent, c);
            }
        }

        dfs_ranges.resize(data.size());

        int visited = 0;
        auto dfs = [&](auto self, int loc) -> void {
            dfs_ranges[loc].first = visited++;
            for (int child : children[loc])
                self(self, child);
            dfs_ranges[loc].second = visited;
        };
        dfs(dfs, 0);
    }

    template<typename V>
    void copy_results_for_duplicate_dictionary_entries(vector<V> &results) const {
        for (int dict_index = 0; dict_index < int(dictionary_word_links.size()); dict_index++) {
            int loc = dictionary_word_links[dict_index];
            if (data[loc].dict_index != dict_index) {
                results[dict_index] = results[data[loc].dict_index];
            }
        }
    }

    /* Returns the number of matches of each dictionary word.
     * Linear in text length and number of dictionary words.
     */
    template<typename S>
    vector<int> count_matches(const S& text) const {
        vector<int> count(dictionary_word_links.size());
        vector<vector<int>> found_with_length;

        auto record_match = [&](int loc, int quantity) {
            int dict_index = data[loc].dict_index;
            if (dict_index == -1) return;

            if (count[dict_index] == 0) {
                if (data[loc].depth >= found_with_length.size())
                    found_with_length.resize(data[loc].depth + 1);
                found_with_length[data[loc].depth].push_back(loc);
            }
            count[dict_index] += quantity;
        };

        int loc = 0;
        for (auto c_ : text) {
            int c = c_;
            assert(MIN_CHAR <= c && c < MIN_CHAR + SIGMA);
            loc = child_link(loc, c);
            record_match(data[loc].dict_suffix_link, 1);
        }
        for (int match_length = int(found_with_length.size()) - 1; match_length > 0; match_length--) {
            for (int loc : found_with_length[match_length])
                record_match(dict_proper_suffix_link(loc), count[data[loc].dict_index]);
        }

        copy_results_for_duplicate_dictionary_entries(count);
        return count;
    }

    /* Returns the starting index of every match of each dictionary word.
     * Linear in the text length, number of dictionary words, and total number of matches.
     */
    template<typename S>
    vector<vector<int>> indices_of_matches(const S& text) const {
        vector<vector<int>> indices(dictionary_word_links.size());

        int loc = 0;
        for (int pos = 0; pos < int(text.size()); pos++) {
            int c = text[pos];
            assert(MIN_CHAR <= c && c < MIN_CHAR + SIGMA);
            loc = child_link(loc, c);
            for (int par = data[loc].dict_suffix_link; par != 0; par = dict_proper_suffix_link(par)) {
                indices[data[par].dict_index].push_back(pos + 1 - data[par].depth);
            }
        }

        /* Notable fact: before duplication, the total number of matches is at most
         * (text length) * (number of distinct dictionary word lengths), which is
         * O(text length * sqrt(sum of dictionary word lengths)).
         */
        copy_results_for_duplicate_dictionary_entries(indices);
        return indices;
    }

    /* Returns the total number of matches over all dictionary words.
     * Duplicate dictionary entries each contribute to the total match count.
     * Linear in the text length.
     */
    template<typename S>
    int64_t count_total_matches(const S& text) const {
        int64_t count = 0;

        int loc = 0;
        for (int pos = 0; pos < int(text.size()); pos++) {
            int c = text[pos];
            assert(MIN_CHAR <= c && c < MIN_CHAR + SIGMA);
            loc = child_link(loc, c);

            count += data[loc].count_suffixes_in_dict;
        }

        return count;
    }
};
// }}}

vi complete_occurences(string text, string pattern) {
    vs p = { pattern };
    trie<'a', 26> tr(all(p));
    return tr.indices_of_matches(text)[0];
}

vi first_end_pos(string text, string pattern, int K) {
    vs p = { pattern };
    trie<'a', 26> tr(all(p));

    vi first(sz(pattern) + 1, INT_MAX / 2);

    int loc = 0;
    F0R (i, sz(text)) {
        loc = tr.child_link(loc, text[i]);

        if (i >= K - 1)
            ckmin(first[loc], i);
    }

    FORd (loc, 1, sz(first))
        ckmin(first[tr.data[loc].suffix_link], first[loc]);

    return first;
}

int main() {
    setIO();

    int N, M, K; re(N, M, K);
    string s; re(s);
    string t; re(t);

    if (M <= K) {
        vi inx = complete_occurences(s, t);

        trav (i, inx) {
            {
                int L = max(0, i + sz(t) - K);
                if (L + 2 * K <= N) {
                    ps("Yes");
                    ps(L + 1, L + 1 + K);
                    return 0;
                }
            }
            {
                int L = min(i, N - K);
                if (L >= K) {
                    ps("Yes");
                    ps(L - K + 1, L + 1);
                    return 0;
                }
            }
        }
    }

    vi left = first_end_pos(s, t, K);

    reverse(all(s));
    reverse(all(t));

    vi right = first_end_pos(s, t, K);

    F0R (use_left, M + 1) {
        int use_right = M - use_left;
        if (max(use_left, use_right) > K) continue;

        int last_left = left[use_left];
        int first_right = N - 1 - right[use_right];

        if (last_left < first_right) {
            ps("Yes");
            ps(last_left - K + 1 + 1, first_right + 1);
            return 0;
        }
    }



    ps("No");

    return 0;
}