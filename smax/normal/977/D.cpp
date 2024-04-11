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

long long arr[105];
map<long long, int> threes;

bool cmp(long long a, long long b) {
    if (threes[a] == threes[b])
        return a < b;
    return threes[a] > threes[b];
}

long long three_log(long long x) {
    long long amt = 0;
    while (x % 3 == 0) {
        x /= 3;
        amt++;
    }
    return amt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        threes[arr[i]] = three_log(arr[i]);
    }

    sort(arr, arr + n, cmp);
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}