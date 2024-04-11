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

int b[50];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> q;
    while (q--) {
        string s;
        int m;
        cin >> s >> m;
        for (int i=0; i<m; i++)
            cin >> b[i];

        vector<int> cnt(26);
        for (char c : s)
            cnt[c-'a']++;

        int ptr = 25;
        string t(m, ' ');
        while (true) {
            vector<int> v;
            for (int i=0; i<m; i++)
                if (b[i] == 0 && t[i] == ' ')
                    v.push_back(i);
            if (v.empty())
                break;

            while (cnt[ptr] < v.size())
                ptr--;
            for (int i : v)
                t[i] = ptr + 'a';
            for (int j=0; j<m; j++)
                if (b[j] != 0)
                    for (int i : v)
                        b[j] -= abs(i - j);
            ptr--;
        }

        cout << t << "\n";
    }

    return 0;
}