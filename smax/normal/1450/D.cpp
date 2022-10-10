#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<bool> has(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            has[--a[i]] = true;
        }

        string ret(n, '0');
        ret[0] = accumulate(has.begin(), has.end(), 0) == n ? '1' : '0';
        int l = 2, r = n + 1;
        while (l < r) {
            int m = (l + r) / 2;
            MinDeque<int> dq;
            has.assign(n, false);
            for (int i=0; i<n; i++) {
                dq.push(a[i]);
                if (i >= m - 1) {
                    has[dq.min()] = true;
                    dq.pop();
                }
            }
            if (accumulate(has.begin(), has.end() - m + 1, 0) == n - m + 1)
                r = m;
            else
                l = m + 1;
        }
        for (int i=l; i<=n; i++)
            ret[i-1] = '1';
        cout << ret << "\n";
    }

    return 0;
}