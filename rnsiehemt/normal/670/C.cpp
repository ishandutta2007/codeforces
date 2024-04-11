#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 200*1000+5;

int n, a[maxn], m, x[maxn], y[maxn];
std::map<int,int> c;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        c[a[i]]++;
    }
    scanf("%d", &m);
    std::pair<std::pair<int,int>, int> best = {{-1, -1}, -1};
    for (int i = 0; i < m; i++) scanf("%d", x+i);
    for (int i = 0; i < m; i++) scanf("%d", y+i);
    for (int i = 0; i < m; i++) {
        int b = x[i], d = y[i];
        std::pair<std::pair<int,int>, int> cur = {{c[b], c[d]}, i};
        domax(best, cur);
    }
    printf("%d\n", best.second+1);
}