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

    // first must be (, last must be )
    if (n % 2 || s[0] == ')' || s[n-1] == '(') {
        cout << ":(\n";
        return 0;
    }
    s[0] = '(';
    s[n-1] = ')';

    // [1, ..., n - 2] must be valid sequence
    int numLeft = 0;
    for (int i=1; i<=n-2; i++)
        if (s[i] == '(')
            numLeft++;
    numLeft = (n - 2) / 2 - numLeft;
    if (numLeft < 0) {
        cout << ":(\n";
        return 0;
    }
    DEBUG(numLeft)
    int bal = 0;
    for (int i=1; i<=n-2; i++) {
        if (s[i] == '?') {
            if (numLeft > 0) {
                s[i] = '(';
                numLeft--;
                bal++;
            } else {
                s[i] = ')';
                bal--;
            }
        } else if (s[i] == '(') {
            bal++;
        } else {
            bal--;
        }
        if (bal < 0) {
            cout << ":(\n";
            return 0;
        }
    }
    cout << s << "\n";

    return 0;
}