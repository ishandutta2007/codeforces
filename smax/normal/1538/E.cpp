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

// 0  1  2   3   4    5
// a, h, ah, ha, aha, hah
const int A = 0, H = 1, AH = 2, HA = 3, AHA = 4, HAH = 5;

struct Data {
    int len;
    long long cnt;
    bool pref[6], suff[6];

    Data() {}

    Data(const string &s) {
        len = (int) s.size();
        cnt = 0;
        for (int i=0; i<len-3; i++)
            if (s.substr(i, 4) == "haha")
                cnt++;
        memset(pref, false, sizeof(pref));
        memset(suff, false, sizeof(suff));

        if (s.substr(0, 1) == "a")
            pref[A] = true;
        if (s.substr(0, 1) == "h")
            pref[H] = true;
        if (s.size() >= 2 && s.substr(0, 2) == "ah")
            pref[AH] = true;
        if (s.size() >= 2 && s.substr(0, 2) == "ha")
            pref[HA] = true;
        if (s.size() >= 3 && s.substr(0, 3) == "aha")
            pref[AHA] = true;
        if (s.size() >= 3 && s.substr(0, 3) == "hah")
            pref[HAH] = true;

        if (s.substr(s.size() - 1, 1) == "a")
            suff[A] = true;
        if (s.substr(s.size() - 1, 1) == "h")
            suff[H] = true;
        if (s.size() >= 2 && s.substr(s.size() - 2, 2) == "ah")
            suff[AH] = true;
        if (s.size() >= 2 && s.substr(s.size() - 2, 2) == "ha")
            suff[HA] = true;
        if (s.size() >= 3 && s.substr(s.size() - 3, 3) == "aha")
            suff[AHA] = true;
        if (s.size() >= 3 && s.substr(s.size() - 3, 3) == "hah")
            suff[HAH] = true;
    }

    friend Data operator + (const Data &a, const Data &b) {
        Data ret;
        ret.len = a.len + b.len;
        ret.cnt = a.cnt + b.cnt + a.suff[H] * b.pref[AHA] + a.suff[HA] * b.pref[HA] + a.suff[HAH] * b.pref[A];
        for (int i=0; i<6; i++) {
            ret.pref[i] = a.pref[i];
            ret.suff[i] = b.suff[i];
        }

        auto check = [&] (bool f, int l, int x, int y) -> bool {
            if (f) return b.len == l && a.suff[x] && b.suff[y];
            else return a.len == l && a.pref[x] && b.pref[y];
        };

        if (check(false, 1, A, H))
            ret.pref[AH] = true;
        if (check(false, 1, H, A))
            ret.pref[HA] = true;
        if (check(false, 1, A, HA) || check(false, 2, AH, A))
            ret.pref[AHA] = true;
        if (check(false, 1, H, AH) || check(false, 2, HA, H))
            ret.pref[HAH] = true;

        if (check(true, 1, A, H))
            ret.suff[AH] = true;
        if (check(true, 1, H, A))
            ret.suff[HA] = true;
        if (check(true, 2, A, HA) || check(true, 1, AH, A))
            ret.suff[AHA] = true;
        if (check(true, 2, H, AH) || check(true, 1, HA, H))
            ret.suff[HAH] = true;

        return ret;
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
        string var;
        unordered_map<string, Data> mp;
        for (int i=0; i<n; i++) {
            string op;
            cin >> var >> op;
            if (op == ":=") {
                string a;
                cin >> a;
                mp[var] = Data(a);
                DEBUG(var, a, mp[var].cnt, mp[var].pref[H]);
            } else {
                string a, b;
                cin >> a >> op >> b;
                mp[var] = mp[a] + mp[b];
                DEBUG(var, a, b, mp[var].cnt);
            }
        }
        cout << mp[var].cnt << "\n";
    }

    return 0;
}