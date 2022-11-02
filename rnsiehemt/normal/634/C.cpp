#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define lc (n*2+1)
#define rc (n*2+2)
#define nm ((nl+nr)/2)
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int Max = 1<<18, MaxNodes = 1<<19;

struct RT {
    int v[MaxNodes];
    void u(int n, int nl, int nr, int ui, int uv, int umax) {
        if (nl == ui && nl+1 == nr) v[n] = std::min(umax, v[n] + uv);
        else {
            if (ui < nm) u(lc, nl, nm, ui, uv, umax);
            else u(rc, nm, nr, ui, uv, umax);
            v[n] = v[lc] + v[rc];
        }
    }
    int q(int n, int nl, int nr, int ql, int qr) {
        if (ql <= nl && nr <= qr) return v[n];
        else {
            int s = 0;
            if (ql < nm) s += q(lc, nl, nm, ql, qr);
            if (nm < qr) s += q(rc, nm, nr, ql, qr);
            return s;
        }
    }
} rta, rtb;

int N, K, A, B, Q;

int main()
{
    scanf("%d%d%d%d%d", &N, &K, &A, &B, &Q);
    for (int i = 0; i < Q; i++) {
        int type; scanf("%d", &type);
        if (type == 1) {
            int d, a; scanf("%d%d", &d, &a);
            rta.u(0, 0, Max, d, a, A);
            rtb.u(0, 0, Max, d, a, B);
        } else {
            int p; scanf("%d", &p);
            printf("%d\n", rtb.q(0, 0, Max, 0, p) + rta.q(0, 0, Max, p+K, Max));
        }
    }
}