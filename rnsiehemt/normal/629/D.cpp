#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

#define nm ((nl+nr)/2)
#define lc (n*2+1)
#define rc (n*2+2)
typedef double real;

const real pi = std::acos(-1.);
const int Max = 1<<17, MaxNodes = 1<<18;

struct RT {
    real max[MaxNodes];
    void u(int n, int nl, int nr, int ui, real uv) {
        if (ui == nl && nl+1 == nr) domax(max[n], uv);
        else {
            if (ui < nm) u(lc, nl, nm, ui, uv);
            else u(rc, nm, nr, ui, uv);
            max[n] = std::max(max[lc], max[rc]);
        }
    }
    real q(int n, int nl, int nr, int ql, int qr) {
        if (ql <= nl && nr <= qr) return max[n];
        else {
            real m = -1e9;
            if (ql < nm) domax(m, q(lc, nl, nm, ql, qr));
            if (nm < qr) domax(m, q(rc, nm, nr, ql, qr));
            return m;
        }
    }
} rt;

int N, idx[100005];
real v[100005], ans;
std::vector<real> allv;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        real r, h;
        scanf("%lf%lf", &r, &h);
        v[i] = pi * r * r * h;
        allv.pb(v[i]);
    }
    allv.pb(0.);
    std::sort(all(allv));
    allv.erase(std::unique(all(allv)), allv.end());
    for (int i = 0; i < N; i++) {
        idx[i] = std::lower_bound(all(allv), v[i]) - allv.begin();
        real foo = v[i] + rt.q(0, 0, Max, 0, idx[i]);
        rt.u(0, 0, Max, idx[i], foo);
        domax(ans, foo);
    }
    printf("%.8lf\n", ans);
}