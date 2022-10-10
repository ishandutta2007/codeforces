#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

pair<int, int> customer[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, l, a;
    cin >> n >> l >> a;
    for (int i=0; i<n; i++)
        cin >> customer[i].first >> customer[i].second;

    sort(customer, customer + n);
    int ret = 0, pred = 0;
    for (int i=0; i<n; i++) {
        ret += (customer[i].first - pred) / a;
        pred = customer[i].first + customer[i].second;
    }
    ret += (l - pred) / a;

    cout << ret << "\n";

    return 0;
}