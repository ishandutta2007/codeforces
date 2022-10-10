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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int a[1<<20], orig[1<<20], len[1<<20], pos[1<<20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    len[1] = 0;
    int pow2 = 2;
    for (int i=2; i<1<<20; i++) {
        len[i] = len[i-1];
        if (i == pow2) {
            len[i]++;
            pow2 *= 2;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int h, g;
        cin >> h >> g;
        int n = 1 << h;
        long long sum = 0;
        for (int i=1; i<n; i++) {
            cin >> a[i];
            orig[i] = a[i];
            pos[a[i]] = i;
            sum += a[i];
        }

        vector<int> ret;
        sort(orig, orig + n);
        for (int j=n-1; j>0; j--) {
            int x = orig[j], i = pos[x];
            assert(i != 0);
            while (2 * i < n) {
                if (a[2*i] == 0 && a[2*i+1] == 0)
                    break;
                if (a[2*i] > a[2*i+1])
                    i = 2 * i;
                else
                    i = 2 * i + 1;
            }
            if (31 - __builtin_clz(i) >= g) {
                i = pos[x];
                sum -= x;
                ret.push_back(i);
                while (2 * i < n) {
                    if (a[2*i] == 0 && a[2*i+1] == 0)
                        break;
                    if (a[2*i] > a[2*i+1]) {
                        a[i] = a[2*i];
                        pos[a[i]] = i;
                        i = 2 * i;
                    } else {
                        a[i] = a[2*i+1];
                        pos[a[i]] = i;
                        i = 2 * i + 1;
                    }
                }
                a[i] = 0;
            }
        }

        assert((int) ret.size() == (1 << h) - (1 << g));
        cout << sum << "\n";
        for (int i : ret)
            cout << i << " ";
        cout << "\n";

        for (int i=1; i<n; i++)
            pos[orig[i]] = 0;
    }

    return 0;
}