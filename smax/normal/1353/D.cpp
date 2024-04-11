#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

struct cmp {
    bool operator () (const pair<int, int> &a, const pair<int, int> &b) const {
        if (a.second - a.first == b.second - b.first)
            return a.first > b.first;
        return a.second - a.first < b.second - b.first;
    }
};

int a[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int i = 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        pq.push({0, n-1});
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int half = (p.first + p.second) / 2;
            a[half] = i++;
            if (p.first < half)
                pq.push({p.first, half - 1});
            if (p.second > half)
                pq.push({half + 1, p.second});
        }

        for (i=0; i<n; i++)
            cout << a[i] << " \n"[i==n-1];
    }

    return 0;
}