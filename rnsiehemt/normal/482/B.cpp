#include <cstdio>
#include <algorithm>

int N, M;
int delta[100005][31];
int cur[100005];
int a[100005];
int tree[400005];
int l[100005];
int r[100005];
int q[100005];

void build(int node, int nl, int nr) {
    if (nl == nr-1) tree[node] = a[nl];
    else {
        int mid = (nl+nr)/2;
        build(node*2+1, nl, mid);
        build(node*2+2, mid, nr);
        tree[node] = (tree[node*2+1] & tree[node*2+2]);
    }
}

int query(int node, int nl, int nr, int ql, int qr) {
    if (nr <= ql || qr <= nl) return ((1<<30)-1);
    else if (ql <= nl && nr <= qr) return tree[node];
    else {
        int mid = (nl+nr)/2;
        return (query(node*2+1, nl, mid, ql, qr) &
                query(node*2+2, mid, nr, ql, qr));
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &l[i], &r[i], &q[i]);
        l[i]--; r[i]--;
        for (int k = 0; k < 30; k++) {
            if (q[i] & (1<<k)) {
                delta[l[i]][k]++;
                delta[r[i]+1][k]--;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < 30; k++) {
            cur[k] += delta[i][k];
            if (cur[k]) a[i] |= (1<<k);
       }
    }

    build(0, 0, N);
    for (int i = 0; i < M; i++) {
        if (query(0, 0, N, l[i], r[i]+1) != q[i]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for (int i = 0; i < N; i++) printf("%d ", a[i]);
    printf("\n");
}