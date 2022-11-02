#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int n;
std::vector<std::pair<int,int>> v;

int main() {
    scanf("%d", &n);
    v.eb(2e9, 2e9);
    for (int i = 0; i < n; i++) {
        int s, d, e; scanf("%d%d", &s, &d);
        e = s+d;
        bool good = true;
        for (auto &p : v) {
            int ss, ee; std::tie(ss, ee) = p;
            if (s < ee && ss < e) {
                good = false;
                break;
            }
        }
        if (good) {
            for (auto it = v.begin(); it != v.end(); it++) {
                if (it->first > s) {
                    v.insert(it, {s, e});
                    printf("%d %d\n", s, e-1);
                    break;
                }
            }
        } else {
            int last = 1;
            for (auto it = v.begin(); it != v.end(); it++) {
                if (last + d <= it->first) {
                    v.insert(it, {last, last+d});
                    printf("%d %d\n", last, last+d-1);
                    break;
                }
                last = it->second;
            }
        }
    }
}