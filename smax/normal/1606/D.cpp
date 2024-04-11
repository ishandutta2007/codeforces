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

template<typename T>
struct RMQ {
    vector<vector<T>> spt;

    RMQ(const vector<T> &a) : spt(1, a) {
        int n = (int) a.size();
        for (int j=1; 1<<j<=n; j++) {
            spt.emplace_back(n - (1 << j) + 1);
            for (int i=0; i+(1<<j)<=n; i++)
                spt[j][i] = min(spt[j-1][i], spt[j-1][i+(1<<(j-1))]);
        }
    }

    T query(int i, int j) {
        int k = __lg(j - i + 1);
        return min(spt[k][i], spt[k][j-(1<<k)+1]);
    }
};

template<typename T>
struct RMQ2 {
    vector<vector<T>> spt;

    RMQ2(const vector<T> &a) : spt(1, a) {
        int n = (int) a.size();
        for (int j=1; 1<<j<=n; j++) {
            spt.emplace_back(n - (1 << j) + 1);
            for (int i=0; i+(1<<j)<=n; i++)
                spt[j][i] = max(spt[j-1][i], spt[j-1][i+(1<<(j-1))]);
        }
    }

    T query(int i, int j) {
        int k = __lg(j - i + 1);
        return max(spt[k][i], spt[k][j-(1<<k)+1]);
    }
};

template<typename T>
struct MinDeque {
    int l = 0, r = 0;
    deque<pair<T, int>> dq;

    void push(T x) {
        while (!dq.empty() && x <= dq.back().first)
            dq.pop_back();
        dq.emplace_back(x, r++);
    }

    void pop() {
        assert(l < r);
        if (dq.front().second == l++)
            dq.pop_front();
    }

    T min() {
        assert(!dq.empty());
        return dq.front().first;
    }
};

template<typename T>
struct MaxDeque {
    int l = 0, r = 0;
    deque<pair<T, int>> dq;

    void push(T x) {
        x = -x;
        while (!dq.empty() && x <= dq.back().first)
            dq.pop_back();
        dq.emplace_back(x, r++);
    }

    void pop() {
        assert(l < r);
        if (dq.front().second == l++)
            dq.pop_front();
    }

    T max() {
        assert(!dq.empty());
        return -dq.front().first;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<RMQ<int>> rmq;
        vector<RMQ2<int>> rmq2;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++)
                cin >> a[i][j];
            rmq.emplace_back(a[i]);
            rmq2.emplace_back(a[i]);
        }

        for (int k=1; k<m; k++) {
            vector<array<int, 5>> v;
            for (int i=0; i<n; i++) {
                // max on left, min on right
                int x = rmq2[i].query(0, k - 1), y = rmq[i].query(0, k - 1), z = rmq2[i].query(k, m - 1), w = rmq[i].query(k, m - 1);
                v.push_back({x, y, z, w, i});
            }
            sort(v.begin(), v.end());
            MinDeque<int> dq1;
            MaxDeque<int> dq2;
            for (auto [x, y, z, w, i] : v) {
                dq1.push(y);
                dq2.push(z);
            }
            DEBUG(k, v);
            int mn = INT_MAX;
            for (int i=0; i<n; ) {
                int j = i;
                while (j < n && v[i][0] == v[j][0]) {
                    mn = min(mn, v[j][3]);
                    DEBUG("POP", j);
                    dq1.pop();
                    dq2.pop();
                    DEBUG("ONCE");
                    j++;
                }
                // everything < j is painted blue, meaning it's max must be less than right side's min
                // and for the other side, everything on left's min must be greater than right side's max
                if (j == n)
                    break;
                if (v[i][0] < dq1.min() && mn > dq2.max()) {
                    cout << "YES\n";
                    vector<bool> blue(n);
                    for (int l=0; l<j; l++)
                        blue[v[l][4]] = true;
                    for (int l=0; l<n; l++)
                        cout << (blue[l] ? 'B' : 'R');
                    cout << " " << k << "\n";
                    goto done;
                }
                i = j;
            }
        }
        cout << "NO\n";
        done:;
    }

    return 0;
}