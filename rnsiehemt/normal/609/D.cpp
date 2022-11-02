#include <bits/stdc++.h>
#define pqueue priority_queue
typedef long long ll;

const int MaxN = 200005;

int N, M, K, t[MaxN];
ll S, a[MaxN], b[MaxN], c[MaxN];

std::vector<std::pair<int, int>> v;
bool go(int D) {
    int mina = 0, minb = 0;
    for (int i = 1; i < D; i++) {
        if (a[i] < a[mina]) mina = i;
        if (b[i] < b[minb]) minb = i;
    }
    std::pqueue<std::pair<ll, int>> q;
    for (int i = 0; i < M; i++) {
        if (t[i] == 1) q.push({-c[i] * a[mina], i});
        else q.push({-c[i] * b[minb], i});
    }
    v.clear();
    ll total = 0;
    for (int i = 0; i < K; i++) {
        std::pair<ll, int> x = q.top(); q.pop();
        total += -x.first;
        if (t[x.second] == 1) v.push_back({x.second, mina});
        else v.push_back({x.second, minb});
    }
    //printf("total %lld\n", total);
    return total <= S;
}

int main()
{
    scanf("%d%d%d%lld", &N, &M, &K, &S);
    for (int i = 0; i < N; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < N; i++) scanf("%lld", &b[i]);
    for (int i = 0; i < M; i++) scanf("%d%lld", &t[i], &c[i]);

    if (!go(N)) printf("-1\n");
    else {
        int lo = 1, hi = N;
        while (lo < hi) {
            int mid = (lo+hi)/2;
            if (go(mid)) hi = mid;
            else lo = mid+1;
        }
        go(lo);
        printf("%d\n", lo);
        for (auto &x : v) printf("%d %d\n", x.first+1, x.second+1);
    }
}