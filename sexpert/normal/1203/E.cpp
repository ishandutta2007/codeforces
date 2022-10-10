#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int cnt[MAXN], pff[MAXN];

bool check(int d) {
    memset(pff, 0, sizeof pff);
    for(int w = 1; w <= 150000; w++) {
        int c = cnt[w];
        for(int k = min(3, c); k > 0; k--) {
            if(!pff[w - 1] && w > 1) {
                pff[w - 1]++;
                continue;
            }
            if(!pff[w]) {
                pff[w]++;
                continue;
            }
            if(!pff[w + 1]) {
                pff[w + 1]++;
                continue;
            }
        }
    }
    int ans = 0;
    for(int w = 1; w <= 150001; w++) {
        if(pff[w])
            ans++;
    }
    return ans >= d;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int lo = 0, hi = 150000;
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        if(check(mi))
            lo = mi;
        else
            hi = mi - 1;
    }
    cout << lo << '\n';
}