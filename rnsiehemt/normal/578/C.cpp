#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define pb push_back
#define eb emplace_back
#define mod(x) ((x)%Mod)
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 200005;

int N;
double a[MaxN];

double f(double x) {
    double sum = 0, min = 0, max = 0;
    for (int i = 0; i < N; i++) {
        sum += a[i] - x;
        domin(min, sum);
        domax(max, sum);
    }
    return max - min;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%lf", &a[i]);

    double lo = -1e6, hi = 1e6;
    for (int i = 0; i < 140; i++) {
        double m1 = (lo+lo+hi)/3, m2 = (lo+hi+hi)/3;
        double k1 = f(m1), k2 = f(m2);
        if (k2 <= k1) lo = m1;
        else hi = m2;
    }
    printf("%.8lf\n", f(lo));
}