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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n + 2);
        for (int i=0; i<n+2; i++)
            cin >> b[i];

        sort(b.begin(), b.end());

        // case 1: sum of a is largest element
        long long sum = accumulate(b.begin(), b.begin() + n + 1, 0LL);
        for (int i=0; i<n+1; i++)
            if (sum - b[i] == b[n+1]) {
                for (int j=0; j<i; j++)
                    cout << b[j] << " ";
                for (int j=i+1; j<n+1; j++)
                    cout << b[j] << " ";
                cout << "\n";
                goto done;
            }

        // case 2: sum of a is second largest element
        sum = accumulate(b.begin(), b.begin() + n, 0LL);
        if (sum == b[n]) {
            for (int i=0; i<n; i++)
                cout << b[i] << " ";
            cout << "\n";
            goto done;
        }

        cout << "-1\n";
        done:;
    }

    return 0;
}