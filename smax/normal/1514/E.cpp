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

        auto query1 = [] (int a, int b) -> bool {
            cout << "1 " << a << " " << b << endl;
            int ret;
            cin >> ret;
            assert(ret != -1);
            return ret;
        };

        vector<int> path(n);
        iota(path.begin(), path.end(), 0);
        stable_sort(path.begin(), path.end(), query1);

        auto query2 = [&] (int x, int p) -> bool {
            cout << "2 " << path[x] << " " << p + 1;
            for (int i=0; i<=p; i++)
                cout << " " << path[i];
            cout << endl;
            int ret;
            cin >> ret;
            assert(ret != -1);
            return ret;
        };

        vector<vector<int>> ret(n, vector<int>(n, 1));
        for (int i=n-1, j=n-2; i>=0; i--) {
            if (i == j) {
                for (int k=0; k<=i; k++)
                    for (int l=i+1; l<n; l++)
                        ret[path[l]][path[k]] = 0;
                j--;
            }
            while (j >= 0 && query2(i, j))
                j--;
        }

        cout << "3\n";
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++)
                cout << ret[i][j];
            cout << "\n";
        }
        cout.flush();
        int x;
        cin >> x;
        if (x == -1)
            return 0;
    }

    return 0;
}