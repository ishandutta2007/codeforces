#include <bits/stdc++.h>

const int maxn = 100*1000+5;

struct RT {
    const static int max = 1<<17, maxnodes = 1<<18;
    double s[maxnodes];
    void up(int n, int nl, int nr, int ui, double uv) {
        if (nl+1 == nr) s[n] += uv;
        else {
            int nm = (nl+nr)/2;
            if (ui < nm) up(n*2+1, nl, nm, ui, uv);
            else up(n*2+2, nm, nr, ui, uv);
            s[n] = s[n*2+1] + s[n*2+2];
        }
    }
    double qu(int n, int nl, int nr, int ql, int qr) {
        if (ql <= nl && nr <= qr) return s[n];
        else {
            int nm = (nl+nr)/2;
            double t = 0.0;
            if (ql < nm) t += qu(n*2+1, nl, nm, ql, qr);
            if (nm < qr) t += qu(n*2+2, nm, nr, ql, qr);
            return t;
        }
    }
} rt, st;

int n, a[maxn];
double inv[maxn], E, f[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a+i);

    for (int i = 0; i < n; i++) {
        E -= ((n-i) * rt.qu(0, 0, RT::max, a[i], n+1)) / (double(n)*(n+1)/2);
        E += st.qu(0, 0, RT::max, a[i], n+1);
        rt.up(0, 0, RT::max, a[i], i+1);
        st.up(0, 0, RT::max, a[i], 1);
    }
    //printf("%lf\n", -E);
    for (int i = 2; i <= n; i++) {
        f[i] = f[i-1] + double(i-1) / 2.0;
        E += f[i] * double(n-i+1)/(double(n)*(n+1)/2);
    }
    printf("%.10lf\n", E);
}