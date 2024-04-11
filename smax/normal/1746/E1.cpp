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

bool query(const vector<int> &a) {
    cout << "? " << a.size();
    for (int x : a)
        cout << " " << x;
    cout << endl;
    string ret;
    cin >> ret;
    return ret == "YES";
}

vector<int> operator + (const vector<int> &a, const vector<int> &b) {
    vector<int> ret = a;
    for (int x : b)
        ret.push_back(x);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> cands(n);
    iota(cands.begin(), cands.end(), 1);
    while (cands.size() > 3) {
        int sz = (int) cands.size();
        vector<int> v1(cands.begin(), cands.begin() + sz / 4);
        vector<int> v2(cands.begin() + sz / 4, cands.begin() + sz / 2);
        vector<int> v3(cands.begin() + sz / 2, cands.begin() + 3 * sz / 4);
        vector<int> v4(cands.begin() + 3 * sz / 4, cands.end());
        bool x = query(v1 + v2), y = query(v1 + v3);
        if (x && y)
            cands = v1 + v2 + v3;
        else if (x && !y)
            cands = v1 + v2 + v4;
        else if (!x && y)
            cands = v1 + v3 + v4;
        else
            cands = v2 + v3 + v4;
    }

    if (cands.size() == 3) {
        bool w = query({cands[0]}), x = query({cands[1]}), y = query({cands[1]}), z = query({cands[0]});
        if (x && y)
            cands = {cands[1]};
        else if (!x && !y)
            cands = {cands[0], cands[2]};
        else if ((w && x) || (y && z))
            cands = {cands[0], cands[1]};
        else if ((w && !x) || (!y && z))
            cands = {cands[0], cands[2]};
        else
            cands = {cands[1], cands[2]};
    }

    for (int x : cands) {
        cout << "! " << x << endl;
        string ret;
        cin >> ret;
        if (ret == ":)")
            return 0;
    }
    assert(false);

    return 0;
}