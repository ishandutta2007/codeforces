#include <cstdio>
#include <algorithm>

int N, Q;
int a[300005];
int p[300005];
int oop[1100005]; // out of position, not object oriented programming :P

int ui, uv;
void update(int n, int nl, int nr) {
    if (nl == ui && ui+1 == nr) {
        oop[n] = uv;
    }
    else {
        int mid = (nl+nr)/2;
        if (ui < mid) update(n*2+1, nl, mid);
        else update(n*2+2, mid, nr);
        oop[n] = oop[n*2+1] + oop[n*2+2];
    }
}

int ql, qr;
int query(int n, int nl, int nr) {
    if (qr <= nl || nr <= ql) return 0;
    else if (ql <= nl && nr <= qr) return oop[n];
    else {
        int mid = (nl+nr)/2;
        return query(n*2+1, nl, mid) + query(n*2+2, mid, nr);
    }
}

int main()
{
    scanf("%d", &N);
    a[0] = p[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
        p[a[i]] = i;
    }
    a[N+1] = p[N+1] = N+1;

    for (int i = 1; i < N; i++) {
        ui = i; uv = p[i] > p[i+1];
        update(0, 0, N+2);
    }

    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int t, x, y; scanf("%d%d%d", &t, &x, &y);
        if (t == 1) {
            ql = x, qr = y;
            printf("%d\n", query(0, 0, N+2)+1);
        }
        else /* t == 2 */ {
            std::swap(a[x], a[y]);
            p[a[x]] = x; p[a[y]] = y;
            
            ui = a[x]-1; uv = p[a[x]-1] > p[a[x]]; update(0, 0, N+2);
            ui = a[x]; uv = p[a[x]] > p[a[x]+1]; update(0, 0, N+2);
            ui = a[y]-1; uv = p[a[y]-1] > p[a[y]]; update(0, 0, N+2);
            ui = a[y]; uv = p[a[y]] > p[a[y]+1]; update(0, 0, N+2);
        }
    }
}