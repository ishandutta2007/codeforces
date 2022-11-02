#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxm = 10*1000+5;

int n, m;
std::vector<std::pair<int, std::string>> v[maxm];

int main() {
    std::cin.tie(0);
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::string s; int j, t;
        std::cin >> s >> j >> t;
        v[j].eb(t, s);
    }
    for (int i = 1; i <= m; i++) {
        std::sort(all(v[i]));
        std::reverse(all(v[i]));
        if (sz(v[i]) == 2 || v[i][1].first > v[i][2].first) {
            std::cout << v[i][0].second << ' ' << v[i][1].second << '\n';
        } else std::cout << "?\n";
    }
}