#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
typedef long long ll;

int N;
int a[200005];
int idx[200005];
ll ans[200005];
int sum[800005];

bool cmp(const int &i, const int &j) {
    return a[i] < a[j];
}

int query(int n, int nl, int nr, int ql, int qr) {
    if (nr <= ql || qr <= nl) return 0;
    else if (ql <= nl && nr <= qr) return sum[n];
    else return query(n*2+1, nl, (nl+nr)/2, ql, qr) + query(n*2+2, (nl+nr)/2, nr, ql, qr);
}

void update(int n, int nl, int nr, int ui) {
    sum[n]++;
    if (nl != nr-1) {
        if (ui < (nl+nr)/2) update(n*2+1, nl, (nl+nr)/2, ui);
        else update(n*2+2, (nl+nr)/2, nr, ui);
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);

    for (int i = 0; i < N; i++) idx[i] = i;
    std::sort(idx, idx+N, cmp);
    //for (int i = 0; i < N; i++) printf("%d\n", idx[i]);
    int s = 0, e = 0;
    while (s < N) {
        while (e < N && a[idx[e]] == a[idx[s]]) e++;
        for (int i = s; i < e; i++) {
            for (int k = 1; k < N && k*(idx[i])+1 < 200002; k++) {
                //printf("idx %d query from %d to %d\n", idx[i], 
                ans[k] += ll(query(0, 0, 200002, k*(idx[i])+1, std::min(200002, k*(idx[i]+1)+1)));
            }
        }
        for (int i = s; i < e; i++) {
            update(0, 0, 200002, idx[i]);
        }
        //for (int k = 1; k < N; k++) printf("%lld%c", ans[k], " \n"[k == N-1]);
        //printf("%d %d\n", s, e);
        s = e;
    }
    for (int k = 1; k < N; k++) printf("%lld%c", ans[k], " \n"[k == N-1]);
}