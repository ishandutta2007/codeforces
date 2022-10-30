#include <cstdio>
#include <queue>

const int inf = 999999999;
struct Max {
    int i, v;
    Max(int ii, int vv) : i(ii), v(vv) { }
    bool operator<(const Max &m) const {
        return v < m.v;
    }
};

struct Min {
    int i, v;
    Min(int ii, int vv) : i(ii), v(vv) { }
    bool operator<(const Min &m) const {
        return v > m.v;
    }
};

int N, S, L;
int a[100005];
int s[100005];
int min[400005];

int query(int n, int nl, int nr, int ql, int qr) {
    if (nr <= ql || qr <= nl) return inf;
    else if (ql <= nl && nr <= qr) return min[n];
    else {
        int mid = (nl+nr)/2;
        return std::min(query(n*2, nl, mid, ql, qr),
            query(n*2+1, mid, nr, ql, qr));
    }
}

void update(int n, int nl, int nr, int qi, int qv) {
    if (qi < nl || nr <= qi) return;
    else if (nl == qi && qi == nr-1) min[n] = qv;
    else {
        int mid = (nl+nr)/2;
        update(n*2, nl, mid, qi, qv);
        update(n*2+1, mid, nr, qi, qv);
        min[n] = std::min(min[n*2], min[n*2+1]);
    }
}

int main()
{
    scanf("%d%d%d", &N, &S, &L);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);

    std::priority_queue<Max> maxq; maxq.push(Max(0, a[0]));
    std::priority_queue<Min> minq; minq.push(Min(0, a[0]));
    int start = 0;
    for (int end = 1; end < N; end++) {
        while (!minq.empty() && a[end] - minq.top().v > S) {
            start = std::max(start, minq.top().i+1);
            minq.pop();
        }
        while (!maxq.empty() && maxq.top().v - a[end] > S) {
            start = std::max(start, maxq.top().i+1);
            maxq.pop();
        }
        minq.push(Min(end, a[end]));
        maxq.push(Max(end, a[end]));
        s[end] = start;
    }
    //for (int i = 0; i < N; i++) {
    //    printf("%d %d\n", i, s[i]);
    //}

    std::fill(min, min+400003, inf);
    for (int i = 0; i < N; i++) {
        if (s[i] <= i-L+1) {
            int best;
            if (s[i] == 0) best = 0;
            else best = query(1, 0, N, s[i]-1, i-L+1+1-1);
            update(1, 0, N, i, best+1);
            //printf("%d %d\n", i, best+1);
            if (i == N-1) {
                if (best >= inf) printf("-1\n");
                else printf("%d\n", best+1);
                return 0;
            }
        }
    }
    printf("-1\n");
}