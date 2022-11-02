#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

std::set<std::string> s;
int n;
std::vector<std::string> v, w;
std::string t;

int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> t;
        v.pb(t);
    }
    for (int i = n-1; i >= 0; i--) {
        if (s.find(v[i]) == s.end()) {
            w.pb(v[i]);
            s.insert(v[i]);
        }
    }
    for (std::string &z : w) std::cout << z << '\n';
}