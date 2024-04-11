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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

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

    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    int n = k1 + k2 + k3;
    vector<int> color(n);
    for (int i=0; i<k1; i++) {
        int a;
        cin >> a;
        a--;
        color[a] = 0;
    }
    for (int i=0; i<k2; i++) {
        int a;
        cin >> a;
        a--;
        color[a] = -1;
    }
    for (int i=0; i<k3; i++) {
        int a;
        cin >> a;
        a--;
        color[a] = 1;
    }

    vector<int> pref(n + 1);
    MinDeque<int> dq;
    for (int i=0; i<n; i++) {
        pref[i+1] = pref[i] + color[i];
        dq.push(pref[i+1]);
    }

    int cnt = 0, cnt2 = 0, delta = 0, ret = k1 + k2 + min(dq.min(), 0);
    for (int i=0; i<n; i++) {
        if (color[i] == 0)
            cnt++;
        else if (color[i] == -1)
            cnt2++;
        delta += color[i];
        ret = min(ret, i + 1 - cnt + k1 - cnt + k2 - cnt2 + dq.min() - delta);
        dq.pop();
    }
    cout << ret << "\n";

    return 0;
}