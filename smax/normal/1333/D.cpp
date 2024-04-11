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

    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<vector<int>> levels;
    int tot = 0;
    while (true) {
        vector<int> v;
        for (int i=0; i<n-1; i++)
            if (s[i] == 'R' && s[i+1] == 'L')
                v.push_back(i);
        if (v.empty())
            break;
        tot += v.size();
        levels.push_back(v);
        for (int i : v) {
            s[i] = 'L';
            s[i+1] = 'R';
        }
    }

    if (k < levels.size() || k > tot) {
        cout << "-1\n";
        return 0;
    }

    for (int i=0, j=0, ptr=0; i<k; i++) {
        if ((int) levels.size() - j == k - i) {
            cout << (int) levels[j].size() - ptr;
            for (int ii=ptr; ii<levels[j].size(); ii++)
                cout << " " << levels[j][ii] + 1;
            cout << "\n";
            j++;
            ptr = 0;
        } else {
            cout << "1 " << levels[j][ptr] + 1 << "\n";
            if (++ptr == levels[j].size()) {
                j++;
                ptr = 0;
            }
        }
    }

    return 0;
}