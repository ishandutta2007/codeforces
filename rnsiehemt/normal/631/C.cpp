#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 200*1000+5;

int N, M, a[MaxN], t[MaxN], r[MaxN];

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    for (int i = 0; i < M; i++) scanf("%d%d", &t[i], &r[i]);
    std::vector<int> v, w;
    for (int i = M-1; i >= 0; i--) if (v.empty() || r[i] > r[v.back()]) v.pb(i);
    for (int i = 0; i < r[v.back()]; i++) w.pb(a[i]);
    std::sort(all(w));
    std::deque<int> deq;
    for (int i : w) deq.push_back(i);
    for (int i = sz(v)-1; i >= 0; i--) {
        int d = t[v[i]], x = r[v[i]];
        int next = (i == 0 ? 0 : r[v[i-1]]);
        if (d == 1) for (int i = x-1; i > next-1; i--) { a[i] = deq.back(); deq.pop_back(); }
        else for (int i = x-1; i > next-1; i--) { a[i] = deq.front(); deq.pop_front(); }
    }
    for (int i = 0; i < N; i++) printf("%d%c", a[i], " \n"[i == N-1]);
}