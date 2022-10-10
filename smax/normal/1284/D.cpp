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

struct Event {
    int t, s, e, in;

    Event(int _t, int _s, int _e, int _in) : t(_t), s(_s), e(_e), in(_in) {}

    bool operator < (const Event &other) {
        if (t == other.t)
            return in < other.in;
        return t < other.t;
    }
};

bool check(int n, vector<int> &sa, vector<int> &ea, vector<int> &sb, vector<int> &eb) {
    multiset<int> st, nd;
    vector<Event> events;
    for (int i=0; i<n; i++) {
        events.emplace_back(sa[i], sb[i], eb[i], 1);
        events.emplace_back(ea[i] + 1, sb[i], eb[i], 0);
    }

    sort(events.begin(), events.end());
    for (Event &ev : events) {
        if (ev.in) {
            if (!st.empty() && (*st.rbegin() > ev.e || *nd.begin() < ev.s))
                return false;
            st.insert(ev.s);
            nd.insert(ev.e);
        } else {
            st.erase(st.find(ev.s));
            nd.erase(nd.find(ev.e));
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> sa(n), ea(n), sb(n), eb(n);
    for (int i=0; i<n; i++)
        cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];

    cout << (check(n, sa, ea, sb, eb) && check(n, sb, eb, sa, ea) ? "YES" : "NO") << "\n";

    return 0;
}