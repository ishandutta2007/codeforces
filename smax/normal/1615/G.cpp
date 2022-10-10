#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

// https://codeforces.com/contest/1615/submission/140496725
// Just how fast is this matching template?
template <class T> struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};

struct MaxMatching {
    MaxMatching(int _n)
        : n(_n), g(_n), mate(n, -1) {}

    void add_edge(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    std::vector<std::pair<int, int>> max_matching() {
        greedy_match();
        blossom_match();
        std::vector<std::pair<int, int>> result;
        for (int i = 0; i < n; i++) {
            if (i < mate[i]) {
                result.push_back({i, mate[i]});
            }
        }
        return result;
    }

  private:
    int n;
    std::vector<std::vector<int>> g;

    std::vector<int> mate; // (i, mate[i]) ,  mate[i] = -1

    void greedy_match() {
        for (int i = 0; i < n; i++) {
            for (int j : g[i]) {
                if (mate[i] == -1 && mate[j] == -1) {
                    mate[i] = mate[j];
                    mate[j] = mate[i];
                }
            }
        }
    }

    void blossom_match() {
        std::vector<int> is_even(n, -1); // (i -> is_even[i])
        std::vector<int> _first(n); // 

        std::vector<std::pair<int, int>> nx(n);

        auto match = [&](auto self, int p, int b) {
            int d = mate[p];
            mate[p] = b;
            if (d == -1 || mate[d] != p) return;
            if (nx[p].second == -1) {
                mate[d] = nx[p].first;
                self(self, nx[p].first, d);
            } else {
                self(self, nx[p].first, nx[p].second);
                self(self, nx[p].second, nx[p].first);
            }
        };

        auto argment = [&](int st) {
            auto first_rec = [&](auto self, int x) {
                if (_first[x] == -1 || is_even[_first[x]] != st)
                    return _first[x];
                return _first[x] = self(self, _first[x]);
            };
            auto first = [&](int x) {
                return first_rec(first_rec, x);
            };

            is_even[st] = st;
            _first[st] = -1;
            nx[st] = {-1, -1};
            simple_queue<int> q;
            q.push(st);
            while (q.size()) {
                int a = q.front();
                q.pop();
                for (int b : g[a]) {
                    if (b == st) continue;
                    if (mate[b] == -1) {
                        mate[b] = a;
                        match(match, a, b);
                        return true;
                    }
                    if (is_even[b] == st) {
                        int x = first(a), y = first(b);
                        if (x == y) continue;
                        int z = -1;
                        while (x != -1 || y != -1) {
                            if (y != -1) std::swap(x, y);
                            if (nx[x] == std::make_pair(a, b)) {
                                z = x;
                                break;
                            }
                            nx[x] = {a, b};
                            x = first(nx[mate[x]].first);
                        }
                        for (int v : {first(a), first(b)}) {
                            while (v != z) {
                                q.push(v);
                                is_even[v] = st;
                                _first[v] = z;
                                v = first(nx[mate[v]].first);
                            }
                        }
                    } else if (is_even[mate[b]] != st) {
                        is_even[mate[b]] = st;
                        nx[b] = {-1, -1};
                        nx[mate[b]] = {a, -1};
                        _first[mate[b]] = b;
                        q.push(mate[b]);
                    }
                }
            }
            return false;
        };

        for (int st = 0; st < n; st++) {
            if (mate[st] == -1) argment(st);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> has(n + 1);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        has[a[i]] = true;
    }

    int sz = min(n, 600);
    vector<int> label(n, -1);
    vector<bool> taken(n + 1);
    vector<pair<int, int>> edges;

    auto addVertex = [&] (int u) -> int {
        if (label[u] == -1)
            label[u] = sz++;
        return label[u];
    };

    auto addEdge = [&] (int u, int v) -> void {
        edges.emplace_back(u, v);
    };

    for (int i=1; i<n; i++)
        if (a[i] != 0 && a[i-1] == a[i])
            taken[a[i]] = true;
    for (int i=0; i<n; ) {
        int j = i;
        while (j < n && a[i] == a[j])
            j++;
        if (a[i] == 0) {
            if ((j - i) % 2 == 0) {
                addEdge(addVertex(i), addVertex(j - 1));
                if (i > 0 && !taken[a[i-1]])
                    addEdge(label[i], a[i-1] - 1);
                if (j < n && !taken[a[j]])
                    addEdge(label[j-1], a[j] - 1);
            } else {
                if (i > 0 && !taken[a[i-1]])
                    addEdge(addVertex(i), a[i-1] - 1);
                if (j < n && !taken[a[j]])
                    addEdge(addVertex(i), a[j] - 1);
            }
        }
        i = j;
    }

    MaxMatching matching(sz);
    for (auto [u, v] : edges)
        matching.add_edge(u, v);
    vector<int> match(sz, -1);
    for (auto [u, v] : matching.max_matching()) {
        match[u] = v;
        match[v] = u;
    }
    int x = 1;

    auto next = [&] () -> int {
        while (has[x])
            x++;
        return x++;
    };

    for (int i=0; i<n; ) {
        int j = i;
        while (j < n && a[i] == a[j])
            j++;
        if (a[i] == 0) {
            if ((j - i) % 2 == 0) {
                if (match[label[i]] == label[j-1]) {
                    for (int k=i; k<j; k+=2)
                        a[k] = a[k+1] = next();
                } else {
                    a[i] = match[label[i]] == -1 ? next() : match[label[i]] + 1;
                    a[j-1] = match[label[j-1]] == -1 ? next() : match[label[j-1]] + 1;
                    for (int k=i+1; k<j-1; k+=2)
                        a[k] = a[k+1] = next();
                }
            } else {
                if (label[i] != -1 && match[label[i]] != -1) {
                    if (i > 0 && match[label[i]] + 1 == a[i-1]) {
                        a[i] = match[label[i]] + 1;
                        for (int k=i+1; k<j; k+=2)
                            a[k] = a[k+1] = next();
                    } else {
                        a[j-1] = match[label[i]] + 1;
                        for (int k=i; k<j-1; k+=2)
                            a[k] = a[k+1] = next();
                    }
                } else {
                    a[j-1] = next();
                    for (int k=i; k<j-1; k+=2)
                        a[k] = a[k+1] = next();
                }
            }
        }
        for (int k=i; k<j; k++)
            cout << a[k] << " ";
        i = j;
    }
    cout << "\n";

    return 0;
}