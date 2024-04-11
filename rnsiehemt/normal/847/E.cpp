#include <bits/stdc++.h>

const int maxn = 100*1000+5;

int n;
char s[maxn];

bool cando(int l, int i, int r, int len) {
    if (l == i || i == r) {
        return r-l <= len;
    } else {
        return std::min(i-l, r-i) + r-l <= len;
    }
}

bool can(int len) {
    int upto = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') {
            int l = upto;
            while (l < i && s[l] == '.') l++;
            if (!cando(l, i, i, len)) return false;
            int r = i;
            while (r+1 < n && s[r+1] != 'P' && cando(l, i, r+1, len)) r++;
            upto = r+1;
            //printf("l = %d, i = %d, r = %d, len = %d\n", l, i, r, len);
        }
    }
    for (int i = upto; i < n; i++) {
        if (s[i] == '*') return false;
    }
    return true;
}

int main() {
    scanf("%d %s", &n, s);
    int lo = 0, hi = maxn*2, best;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (can(mid)) {
            best = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    printf("%d\n", best);
}