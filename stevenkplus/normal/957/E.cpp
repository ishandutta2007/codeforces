// E2.cpp
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef long double ld;
const int MAXN = 100100;
#define div scott
#define abs steven

ld div(int a, int b) {
    return -a / ld(b);
}

ld abs(ld x) {
    if (x<0) return -x;
    return x;
}

bool eq(ld a, ld b) {
    return abs(a-b)<1e-11;
}

int n;
void go(vector<pair<ld, ld> > &v) {
    int lst = 0;
    ld last;
    for(int i = 0; i < n; ++i) {
        if (!eq(last, v[i].first)) {
          lst = i;
          last = v[i].first;
        }
        v[i].first = lst;
    }
    for(int i = 0; i < n; ++i) {
        swap(v[i].first, v[i].second);
    }
    sort(v.begin(), v.end());
}

void go2(vector<pair<ld, ld> > &v) {
    for(int i = 0; i < n; ++i) {
        v[i].second *= -1;
    }
}

int BIT[MAXN];
int query(int x) {
    ++x;
    int s = 0;
    while (x) {
        s += BIT[x];
        x -= x & -x;
    }
    return s;
}

void inc(int x) {
    ++x;
    while (x < MAXN) {
        BIT[x] += 1;
        x += x & -x;
    }
}

int main() {
    int  w;
    vector<pair<ld, ld> > v;
    scanf("%d %d", &n, &w);
    for (int i = 0; i < n; ++i) {
        int a, vv;
        scanf("%d %d", &a, &vv);
        ld lo = div(a, vv - w);
        ld hi = div(a, vv + w);
        v.push_back(pair<ld, ld>(lo, hi));
    }
    sort(v.begin(), v.end());
    go(v);
    go(v);

    go2(v);
    sort(v.begin(), v.end());
    go2(v);

    long long ans = (long long)(n) * (n - 1) / 2;
    for(int i = 0; i < n; ++i) {
        ans -= query(v[i].second - 1);
        inc(v[i].second);
    }
    cout << ans << "\n";
}