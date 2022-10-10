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

int queries;

string query(int r, int c) {
    assert(++queries <= 130);
    cout << r << " " << c << endl;
    string ret;
    cin >> ret;
    return ret;
}

int c;

void sweep(int r) {
    if (c == 8) {
        for (c=7; c>0; c--) {
            string ret = query(r, c);
            if (ret == "Done") {
                return;
            } else if (ret.find("Up") != ret.npos) {
                return sweep(r);
            } else if (ret.find("Down") != ret.npos) {
                ret = query(r + 1, c);
                if (ret == "Done")
                    return;
                return sweep(r + 1);
            }
        }
        string ret = query(r + 1, c = 1);
        if (ret == "Done")
            return;
        return sweep(r + 1);
    } else {
        for (c=c==1?2:1; c<=8; c++) {
            string ret = query(r, c);
            if (ret == "Done") {
                return;
            } else if (ret.find("Up") != ret.npos) {
                return sweep(r);
            } else if (ret.find("Down") != ret.npos) {
                ret = query(r + 1, c);
                if (ret == "Done")
                    return;
                return sweep(r + 1);
            }
        }
        string ret = query(r + 1, c = 8);
        if (ret == "Done")
            return;
        return sweep(r + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        queries = 0;
        string ret = query(1, c = 1);
        if (ret == "Done")
            continue;
        sweep(1);
    }

    return 0;
}