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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

template<typename T>
struct BIT {
    int n, lg;
    vector<T> bit;

    BIT(int _n) : n(_n), lg(__lg(n)), bit(n + 1) {}

    BIT(const vector<T> &a) : n((int) a.size()), lg(__lg(n)), bit(n + 1) {
        for (int i=1; i<=n; i++) {
            bit[i] += a[i-1];
            if (i + (i & -i) <= n)
                bit[i+(i&-i)] += bit[i];
        }
    }

    T query(int i) {
        T ret = 0;
        for (; i>0; i-=i&-i)
            ret += bit[i];
        return ret;
    }

    T query(int l, int r) {
        return query(r) - query(l-1);
    }

    void update(int i, T val) {
        for (; i<=n; i+=i&-i)
            bit[i] += val;
    }

    int kth(T k) {
        int ret = 0;
        for (int i=lg; i>=0; i--) {
            ret += 1 << i;
            if (ret <= n && bit[ret] < k)
                k -= bit[ret];
            else
                ret -= 1 << i;
        }
        return ret + 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        int n = (int) a.size();

        vector<vector<int>> pos(26);
        for (int i=0; i<n; i++)
            pos[a[i]-'A'].push_back(i + 1);

        auto count = [&] (const string &s) -> long long {
            BIT<int> bit(n);
            vector<int> ptr(26);
            long long ret = 0;
            for (char c : s) {
                ret += bit.query(pos[c-'A'][ptr[c-'A']], n);
                bit.update(pos[c-'A'][ptr[c-'A']++], 1);
            }
            return ret;
        };

        vector<char> order{'A', 'N', 'O', 'T'};
        long long mx = -1;
        string best;
        do {
            string cur;
            for (char c : order)
                cur += string(pos[c-'A'].size(), c);
            long long cnt = count(cur);
            if (cnt > mx) {
                mx = cnt;
                best = cur;
            }
        } while (next_permutation(order.begin(), order.end()));
        cout << best << "\n";
        DEBUG(mx);
    }

    return 0;
}