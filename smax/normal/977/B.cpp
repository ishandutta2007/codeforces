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
    string s;
    cin >> n >> s;

    vector<bool> ch(26);
    for (int i=0; i<n; i++)
        ch[s[i] - 'A'] = true;

    int smallest = -1;
    string biggestSub;
    for (int i=0; i<26; i++)
        for (int j=0; j<26; j++) {
            int tot = 0;
            for (int k=0; k<n-1; k++)
                if (s[k] == char('A' + i) && s[k+1] == char('A' + j))
                    tot++;
            if (tot > smallest) {
                smallest = tot;
                biggestSub = string(1, 'A' + i) + string(1, 'A' + j);
            }
        }
    cout << biggestSub << "\n";

    return 0;
}