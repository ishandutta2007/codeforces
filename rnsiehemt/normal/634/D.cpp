#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define nm ((nl+nr)/2)
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxM = 200005, Max = 1<<30, MaxNodes = 62*MaxM;

int M, next[MaxM];
ll D, G, x[MaxM], c[MaxM];
std::pair<ll, ll> p[MaxM];

struct RT {
    int min[MaxNodes], l[MaxNodes], r[MaxNodes], N;
    RT() : N(1) { }
    void check(int &a) {
        if (!a) a = N++;
    }
    int get(int i) {
        return (i ? c[i] : 2e9);
    }
    int get2(int i) {
        return (i ? get(min[i]) : 2e9);
    }
    void u(int n, int nl, int nr, int ui, int uv) {
        if (nl == ui && nl+1 == nr) min[n] = uv;
        else {
            if (ui < nm) { check(l[n]); u(l[n], nl, nm, ui, uv); }
            else { check(r[n]); u(r[n], nm, nr, ui, uv); }
            min[n] = (get2(l[n]) < get2(r[n]) ? min[l[n]] : min[r[n]]);
        }
    }
    int q(int n, int nl, int nr, int ql, int qr) {
        if (ql <= nl && nr <= qr) return min[n];
        else {
            int m = 0, qmin = 0, mval = 2e9;
            if (ql < nm && l[n] && domin(mval, get(qmin = q(l[n], nl, nm, ql, qr)))) m = qmin;
            if (nm < qr && r[n] && domin(mval, get(qmin = q(r[n], nm, nr, ql, qr)))) m = qmin;
            return m;
        }
    }
} rt;

int main()
{
    scanf("%lld%lld%d", &D, &G, &M);
    M++;
    for (int i = 1; i < M; i++) scanf("%lld%lld", &p[i].first, &p[i].second);
    std::sort(p, p+M);
    for (int i = 1; i < M; i++) {
        x[i] = p[i].first;
        c[i] = p[i].second;
        rt.u(0, 0, Max, x[i], i);
    }
    std::stack<int> s;
    for (int i = M-1; i >= 0; i--) {
        while (!s.empty() && c[i] <= c[s.top()]) s.pop();
        next[i] = (s.empty() ? M : s.top());
        s.push(i);
    }
    int i = 0;
    ll g = G, cost = 0;
    while (true) {
        if (x[i]+g >= D) break;
        else if (next[i] < M && x[next[i]] - x[i] <= G) {
            ll dist = x[next[i]] - x[i];
            if (dist > g) {
                cost += (dist - g) * c[i];
                g = dist;
            }
            g -= dist;
            i = next[i];
        } else if (x[i]+G >= D) {
            cost += (D - (x[i]+g)) * c[i];
            break;
        } else {
            cost += (G-g) * c[i];
            g = G;
            int min = rt.q(0, 0, Max, x[i]+1, x[i]+G+1);
            if (min == 0) {
                printf("-1\n");
                return 0;
            }
            g -= x[min] - x[i];
            i = min;
        }
    }
    printf("%lld\n", cost);
}