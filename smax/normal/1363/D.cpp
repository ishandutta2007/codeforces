#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
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

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int tot = 0;
        vector<bool> in(n + 1);
        vector<vector<int>> s(k);
        for (int i=0; i<k; i++) {
            int c;
            cin >> c;
            tot += c;
            while (c--) {
                int x;
                cin >> x;
                s[i].push_back(x);
                in[x] = true;
            }
        }

        cout << "? " << n;
        for (int i=1; i<=n; i++)
            cout << " " << i;
        cout << endl;
        int mx;
        cin >> mx;

        if (tot < n) {
            cout << "? " << n - tot;
            for (int i=1; i<=n; i++)
                if (!in[i])
                    cout << " " << i;
            cout << endl;

            int x;
            cin >> x;
            if (x == mx) {
                cout << "!";
                for (int i=0; i<k; i++)
                    cout << " " << mx;
                cout << endl;

                string ret;
                cin >> ret;
                continue;
            }
        }

        int l = 0, r = k - 1;
        while (l < r) {
            int m = (l + r) / 2, c = 0;
            for (int i=l; i<=m; i++)
                c += s[i].size();

            cout << "? " << c;
            for (int i=l; i<=m; i++)
                for (int x : s[i])
                    cout << " " << x;
            cout << endl;

            int x;
            cin >> x;
            if (x == mx)
                r = m;
            else
                l = m + 1;
        }

        vector<bool> inL(n + 1);
        vector<int> query;
        for (int x : s[l])
            inL[x] = true;
        for (int i=1; i<=n; i++)
            if (!in[i] || (in[i] && !inL[i]))
                query.push_back(i);

        cout << "? " << query.size();
        for (int x : query)
            cout << " " << x;
        cout << endl;

        int x;
        cin >> x;

        cout << "!";
        for (int i=0; i<k; i++) {
            if (i == l)
                cout << " " << x;
            else
                cout << " " << mx;
        }
        cout << endl;

        string ret;
        cin >> ret;
    }

    return 0;
}