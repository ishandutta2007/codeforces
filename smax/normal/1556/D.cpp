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
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

long long query(const string &s, int i, int j) {
    cout << s << " " << i << " " << j << endl;
    long long ret;
    cin >> ret;
    assert(ret != -1);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    // determine first three
    long long ab = query("or", 1, 2) + query("and", 1, 2);
    long long ac = query("or", 1, 3) + query("and", 1, 3);
    long long bc = query("or", 2, 3) + query("and", 2, 3);
    long long a = (ab - bc + ac) / 2;
    long long b = ab - a;
    long long c = ac - a;
    vector<long long> v{a, b, c};

    // get rest
    for (int i=4; i<=n; i++) {
        long long sum = query("or", 1, i) + query("and", 1, i);
        v.push_back(sum - a);
    }

    sort(v.begin(), v.end());
    cout << "finish " << v[k-1] << endl;

    return 0;
}