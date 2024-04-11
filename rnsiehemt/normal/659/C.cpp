#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int n, m;
bool s[1000*1000+5];
std::vector<int> v;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        if (a < 1000*1000) s[a] = true;
    }
    for (int i = 1; i <= m; i++) {
        if (!s[i]) {
            m -= i;
            v.pb(i);
        }
    }
    printf("%d\n", sz(v));
    for (int i : v) printf("%d ", i);
    printf("\n");
}