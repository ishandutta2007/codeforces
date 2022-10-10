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

int ask(const string &s, int i, int j) {
    cout << s << " " << i + 1 << " " << j + 1 << endl;
    int x;
    cin >> x;
    assert(x != -1);
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // get n - 1 XORs, which derive all the XORs
    vector<int> xxx{0};
    for (int i=0; i<n-1; i++)
        xxx.push_back(ask("XOR", i, i + 1));

    vector<int> pref0(n), pref1(n);
    for (int i=1; i<n; i++) {
        pref0[i] = xxx[i] ^ pref0[i-1];
        pref1[i] = i == 1 ? 0 : (xxx[i] ^ pref1[i-1]);
    }

    // get AND of first and second
    int aaa = ask("AND", 0, 1);

    // however, not uniquely defined as we could invert every single bit
    // thus, let's do AND two more times
    int fin = ask("AND", 0, n - 1), fin2 = ask("AND", 1, n - 1);

    // building time!
    vector<int> ret(n);
    for (int j=0; j<16; j++) {
        if (aaa & (1 << j)) {
            // both 1
            ret[0] |= 1 << j;
            ret[1] |= 1 << j;
        } else if (!(xxx[1] & (1 << j))) {
            // both 0
        } else {
            // depends, we'll try both, first let's see if ret[0] = 0
            vector<int> test(n);
            for (int i=1; i<n; i++)
                test[i] = !!(pref0[i] & (1 << j));
            bool ok = true;
            assert(test[1] == 1);
            for (int i=2; i<n; i++)
                if ((test[i] ^ 1) != !!(pref1[i] & (1 << j))) {
                    ok = false;
                    break;
                }
            if (((fin & (1 << j)) && !(test[0] && test[n-1])) || (!(fin & (1 << j)) && test[0] && test[n-1]))
                ok = false;
            if (((fin2 & (1 << j)) && !(test[1] && test[n-1])) || (!(fin2 & (1 << j)) && test[1] && test[n-1]))
                ok = false;
            if (ok) {
                ret[1] |= 1 << j;
            } else {
                ret[0] |= 1 << j;
            }
        }
    }

    // recover the rest
    for (int i=2; i<n; i++)
        ret[i] = pref0[i] ^ ret[0];

    cout << "!";
    for (int x : ret)
        cout << " " << x;
    cout << endl;

    return 0;
}