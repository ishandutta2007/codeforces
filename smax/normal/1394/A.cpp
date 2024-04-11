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

    int n, d, m;
    cin >> n >> d >> m;
    vector<int> non, muzzle;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a <= m) non.push_back(a);
        else muzzle.push_back(a);
    }

    sort(non.rbegin(), non.rend());
    sort(muzzle.rbegin(), muzzle.rend());

    long long ret = 0, cur = 0;
    for (int x : non) cur += x;
    int i = non.size(), j = 0, blocked = 0;
    while (j < muzzle.size() && (int) muzzle.size() - j - 1 + (int) non.size() - i - blocked >= d) {
        cur += muzzle[j++];
        blocked += d;
    }
//    DEBUG(cur, i, j, (j + blocked - ((int) non.size() - i) < muzzle.size() ? muzzle[j + blocked - ((int) non.size() - i)] : 0), cur + (j < muzzle.size() ? muzzle[j] : 0), blocked)
    ret = cur + (j < (int) muzzle.size() - max(blocked - ((int) non.size() - i), 0) ? muzzle[j] : 0);
    while (i - 1 >= 0) {
        cur -= non[--i];
        while (j < muzzle.size() && (int) muzzle.size() - j - 1 + (int) non.size() - i - blocked >= d) {
            cur += muzzle[j++];
            blocked += d;
        }
//        DEBUG(cur, i, j, (j + blocked - ((int) non.size() - i) < muzzle.size() ? muzzle[j + blocked - ((int) non.size() - i)] : 0), cur + (j < muzzle.size() ? muzzle[j] : 0), blocked)
        ret = max(ret, cur + (j < (int) muzzle.size() - max(blocked - ((int) non.size() - i), 0) ? muzzle[j] : 0));
    }

    cout << ret << "\n";

    return 0;
}