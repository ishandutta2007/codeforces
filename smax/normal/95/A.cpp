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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    unordered_set<string> st;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        st.insert(s);
    }
    string w;
    char c;
    cin >> w >> c;

    vector<bool> change(w.size());
    for (int i=0; i<(int)w.size(); i++) {
        string cur;
        int mark = -1;
        for (int j=i; j<(int)w.size(); j++) {
            cur += tolower(w[j]);
            if (st.count(cur))
                mark = j;
        }
        for (int j=i; j<=mark; j++)
            change[j] = true;
    }

    for (int i=0; i<(int)w.size(); i++)
        if (change[i]) {
            if (tolower(w[i]) == c) {
                char to = c == 'a' ? 'b' : 'a';
                w[i] = islower(w[i]) ? to : toupper(to);
            } else {
                w[i] = islower(w[i]) ? c : toupper(c);
            }
        }
    cout << w << "\n";

    return 0;
}