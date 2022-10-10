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

    vector<int> x(n), cnt(n);
    cnt[0]++;
    for (int i=1; i<n; i++) {
        x[i] = ask("XOR", 0, i);
        cnt[x[i]]++;
    }

    int dup = -1;
    for (int i=0; i<n; i++)
        if (cnt[i] > 1) {
            dup = i;
            break;
        }

    vector<int> ret(n);
    if (dup == -1) {
        for (int i=0; i<n; i++) {
            if (x[i] == 1) {
                int a = ask("AND", 0, i);
                for (int j=2; j<n; j*=2)
                    if (a & j)
                        ret[0] |= j;
            } else if (x[i] == 2) {
                int a = ask("AND", 0, i);
                if (a & 1)
                    ret[0] |= 1;
            }
        }
        for (int i=1; i<n; i++)
            ret[i] = ret[0] ^ x[i];
    } else {
        int idx = -1, idx2 = -1;
        for (int i=0; i<n; i++)
            if (x[i] == dup) {
                if (idx == -1) idx = i;
                else idx2 = i;
            }
        ret[idx] = ask("AND", idx, idx2);
        for (int i=0; i<n; i++)
            if (i != idx)
                ret[i] = ret[idx] ^ x[idx] ^ x[i];
    }

    cout << "!";
    for (int a : ret)
        cout << " " << a;
    cout << endl;

    return 0;
}