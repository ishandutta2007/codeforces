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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k;
    string s, t;
    cin >> k >> s >> t;

    vector<int> a(k);
    for (int i=k-1; i>=0; i--) {
        if (t[i] >= s[i])
            a[i] = t[i] - s[i];
        else {
            int j = i - 1;
            while (t[j] == 'a')
                j--;
            assert(t[j] > 'a');
            t[j++]--;
            while (j < i)
                t[j++] += 25;
            a[i] = t[i] + 26 - s[i];
        }
    }
    DEBUG(a)
    assert(a[k-1] % 2 == 0);

    for (int i=0; i<k; i++) {
        if (a[i] % 2)
            a[i+1] += 26;
        a[i] /= 2;
    }
    DEBUG(a)

    for (int i=k-1; i>=0; i--) {
        int val = int(s[i]) + a[i];
        if (val > 'z') {
            val -= 26;
            a[i-1]++;
        }
        s[i] = val;
        DEBUG(s, a)
    }

    cout << s << "\n";

    return 0;
}