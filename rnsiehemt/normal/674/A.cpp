#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 5005;

int n, t[maxn], o[maxn], ans[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", t+i);
    for (int s = 0; s < n; s++) {
        std::priority_queue<std::pair<int, int>> q;
        std::fill(o, o+n+3, 0);
        for (int e = s; e < n; e++) {
            o[t[e]]++;
            q.emplace(o[t[e]], -t[e]);
            while (o[-q.top().second] != q.top().first) {
                q.pop();
            }
            ans[-q.top().second]++;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
}