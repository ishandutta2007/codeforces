// weird but elegant "intended solution"
#include <cstdio>

int N, sz;
double d[200010]; // d[i] = delta between elements i-1 and i
double l /* last */, t /* total */;

int main()
{
    scanf("%d", &N);
    sz = 1;
    for (int i = 0; i < N; i++) {
        int cmd; scanf("%d", &cmd);
        if (cmd == 1) {
            int a; double x; scanf("%d%lf", &a, &x);
            d[0] += x;
            d[a] -= x;
            t += double(a) * x;
            if (a == sz) l += x;
        }
        else if (cmd == 2) {
            double k; scanf("%lf", &k);
            d[sz] += k;
            d[sz+1] -= k;
            sz++;
            t += k;
            l = k;
        }
        else /* cmd == 3 */ {
            double ltmp = l;
            l -= d[sz-1];
            t -= ltmp;
            d[sz-1] -= ltmp;
            d[sz] += ltmp;
            sz--;
        }
        printf("%.7lf\n", t / double(sz));
    }
}