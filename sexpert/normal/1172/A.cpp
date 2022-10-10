#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
int n, a[MAXN], b[MAXN];
bool has[MAXN];

bool can(int k) {
    memset(has, false, sizeof has);
    for(int i = 0; i < n; i++)
        has[a[i]] = true;
    if(k >= n) {
        bool poss = true;
        for(int i = 0; i < k - n; i++)
            has[b[i]] = true;
        for(int j = 1; j <= n; j++) {
            if(!has[j]) poss = false;
            if(k - n - 1 + j < n)
                has[b[k - n - 1 + j]] = true;
        }
        if(poss)
            return true;
    }

    memset(has, false, sizeof has);
    for(int i = 0; i < n; i++)
        has[a[i]] = true;

    int pt;
    for(pt = 0; pt < n; pt++)
        if(b[pt] == 1) break;
    if(pt == n)
        return false;
    for(int i = pt; i < n; i++)
        if(b[i] != i - pt + 1) return false;
    int have = n - pt;
    //cout << pt << " " << have << " " << n - have << " " << k << '\n';
    if(n - have > k) {
        //cout << n - have << " " << k << '\n';
        return false;
    }
    for(int m = 1; m + have <= n; m++) {
        if(!has[m + have]) return false;
        has[b[m - 1]] = true;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    int lo = 0, hi = 2*n;
    while(lo < hi) {
        int mi = (lo + hi)/2;
        if(can(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    cout << lo << '\n';
}