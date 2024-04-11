#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50, INF = (int)1e9;

int n, m;
int a[N];

int get_seg(int mn, int l, int r) {
    if(l <= mn && mn <= r) return mn;
    if(mn > r) return INF;
    return l;
}

bool check(int x) {
    int mn = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] + x >= m) {
            mn = min(get_seg(mn, 0, (a[i] + x) % m), get_seg(mn, a[i], m - 1));
        }
        else {
            mn = get_seg(mn, a[i], a[i] + x);
        }
    }
    return mn != INF;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = -1, r = m - 1, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
}