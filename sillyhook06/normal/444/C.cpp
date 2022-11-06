#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, t, l, r, x, mark[410000];
long long delta[410000], sum[410000];

void read(int &x) {
    char k;
    for (k = getchar(); k <= 32; k = getchar());
    for (x = 0; '0' <= k; k = getchar())    x = x * 10 + k - '0';
}

void mkt(int k, int q, int h) {
    if (q < h) {
        mkt(k * 2, q, (q + h) / 2);
        mkt(k * 2 + 1, (q + h) / 2 + 1, h);
        mark[k] = 0;
    }else   mark[k] = q;
}

long long query(int k, int q, int h, int l, int r) {
    if (l <= q && h <= r)   return sum[k];
    if (r <= (q + h) / 2)   return query(k * 2, q, (q + h) / 2, l, r) + 1LL * delta[k] * (r - l + 1);
    if ((q + h) / 2 < l)    return query(k * 2 + 1, (q + h) / 2 + 1, h, l, r) + 1LL * delta[k] * (r - l + 1);
    return query(k * 2, q, (q + h) / 2, l, (q + h) / 2) + query(k * 2 + 1, (q + h) / 2 + 1, h, (q + h) / 2 + 1, r) + 1LL * delta[k] * (r - l + 1);
}

void Clear(int k, int q, int h) {
    if (mark[k] > 0) {
        delta[k] += abs(mark[k] - x);
        sum[k] += 1LL * abs(mark[k] - x) * (h - q + 1);
    }else {
        Clear(k * 2, q, (q + h) / 2);
        Clear(k * 2 + 1, (q + h) / 2 + 1, h);
        sum[k] = sum[k * 2] + sum[k * 2 + 1] + 1LL * delta[k] * (h - q + 1);
    }
    mark[k] = -1;
}

void modify(int k, int q, int h) {
    if (l <= q && h <= r)   Clear(k, q, h), mark[k] = x;
    else {
        if (mark[k] > 0)    mark[k * 2] = mark[k * 2 + 1] = mark[k], mark[k] = 0;
        if (r <= (q + h) / 2)   modify(k * 2, q, (q + h) / 2);
        else    if ((q + h) / 2 < l)    modify(k * 2 + 1, (q + h) / 2 + 1, h);
        else    modify(k * 2, q, (q + h) / 2), modify(k * 2 + 1, (q + h) / 2 + 1, h);
        mark[k] = 0;
        sum[k] = sum[k * 2] + sum[k * 2 + 1] + 1LL * delta[k] * (h - q + 1);
    }
}

int main() {
    read(n); read(m);
    mkt(1, 1, n);
    while (m--) {
        read(t); read(l); read(r);
        if (t == 1) {
            read(x);
            modify(1, 1, n);
        }else {
            printf("%I64d\n", query(1, 1, n, l, r));
        }
    }
}