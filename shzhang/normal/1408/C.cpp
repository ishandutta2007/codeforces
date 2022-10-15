#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int a[100005];
vector<double> seq, seq2;
int n;

double tim2pos(vector<double>& vec, double tim, bool is2nd)
{
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2 + 1;
        if (vec[mid] < tim) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    //debug("here %d", l);
    if (!is2nd) {
        //debug("here1 %d", l);
        return (double)a[l] + (double)(tim - vec[l]) * (double)(l + 1);
    } else {
        //debug("here2 %d", l);
        return (double)a[n + 1 - l] - (double)(tim - vec[l]) * (double)(l + 1);
    }
}

void work()
{
    int l;
    scanf("%d%d", &n, &l);
    seq.clear(); seq2.clear();
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    a[0] = 0; a[n+1] = l;
    double t = 0;
    for (int i = 0; i <= n + 1; i++) {
        if (i) {
            t += (double)(a[i] - a[i-1]) / (double)i;
        }
        seq.push_back(t);
    }
    t = 0;
    for (int i = n + 1; i >= 0; i--) {
        if (i <= n) {
            t += (double)(a[i+1] - a[i]) / (double)(n - i + 1);
        }
        seq2.push_back(t);
        //debug("%.10f", t);
    }
    double L = seq[0], R = seq[n+1];
    while (R - L > 1e-7) {
        double mid = (L + R) / 2.0;
        if (tim2pos(seq, mid, false) < tim2pos(seq2, mid, true)) {
            L = mid;
        } else {
            R = mid;
        }
        //debug("here2");
    }
    //printf("%.10f %.10f\n", tim2pos(seq, 3.666666, false), tim2pos(seq2, 3.666666, true));
    printf("%.10f\n", L);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}