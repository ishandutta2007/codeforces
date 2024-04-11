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

int len[100005];
string ret[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.length();

    vector<int> stk;
    vector<char> uniq;
    auto check = [&] (char c) {
        assert(!uniq.empty() && (uniq.size() == 1 || uniq[(int)uniq.size()-2] != c));
        return uniq.size() == 1 || uniq[(int)uniq.size()-2] < c;
    };

    for (int i=n-1; i>=0; i--) {
        while (uniq.size() >= 2 && uniq[(int)uniq.size()-1] == uniq[(int)uniq.size()-2])
            uniq.pop_back();
        if (!stk.empty() && s[stk.back()] == s[i] && i + 1 == stk.back() && check(s[i])) {
            stk.pop_back();
            assert(!uniq.empty());
            if (stk.empty() || (!stk.empty() && s[stk.back()] != uniq.back()))
                uniq.pop_back();
        } else {
            stk.push_back(i);
            if (uniq.empty() || s[i] != uniq.back())
                uniq.push_back(s[i]);
        }
        len[i] = stk.size();
        if (len[i] > 10) {
            for (int j=0; j<5; j++)
                ret[i] += s[stk[(int)stk.size()-j-1]];
            ret[i] += "...";
            ret[i] += s[stk[1]];
            ret[i] += s[stk[0]];
        } else {
            for (int j : stk)
                ret[i] += s[j];
            reverse(ret[i].begin(), ret[i].end());
        }
    }

    for (int i=0; i<n; i++)
        cout << len[i] << " " << ret[i] << "\n";

    return 0;
}