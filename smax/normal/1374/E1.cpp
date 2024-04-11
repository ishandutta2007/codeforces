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

    int n, k;
    cin >> n >> k;

    vector<int> alice, bob, both;
    for (int i=0; i<n; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (a && b)
            both.push_back(t);
        else if (a)
            alice.push_back(t);
        else if (b)
            bob.push_back(t);
    }

    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());
    sort(both.begin(), both.end());

    int i, j, ret = 0;
    for (i=0; i<min(k, (int) alice.size()); i++)
        ret += alice[i];
    for (j=0; j<min(k, (int) bob.size()); j++)
        ret += bob[j];

    if ((i < k && both.size() < k - i) || (j < k && both.size() < k - j)) {
        cout << "-1\n";
        return 0;
    }

    int aCnt = i, bCnt = j;
    i--, j--;
    for (int t : both) {
        if (aCnt < k || bCnt < k) {
            aCnt++;
            bCnt++;
            ret += t;
            if (aCnt > k) {
                ret -= alice[i--];
                aCnt--;
            }
            if (bCnt > k) {
                ret -= bob[j--];
                bCnt--;
            }
        } else if (i >= 0 && j >= 0 && t < alice[i] + bob[j]) {
            ret += t - alice[i] - bob[j];
            i--;
            j--;
        }
    }

    cout << ret << "\n";

    return 0;
}