#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m, A, B, v;
    cin >> n >> m >> A >> B >> v;
    vector <int> a(A), b(B);
    for(int i = 0; i < A; i ++) cin >> a[i];
    for(int i = 0; i < B; i ++) cin >> b[i];
    int q;
    cin >> q;
    while(q --) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        if(y1 == y2) {
            cout << abs(x1 - x2) << endl;
            continue;
        }
        if(x1 > x2) swap(x1, x2), swap(y1, y2);
        int p = lower_bound(a.begin(), a.end(), x1) - a.begin();
        int t = abs(y1-y2);
        int ans = 1e9;
        for(int j = p-1; j <= p+1; j ++) if(0 <= j && j < A) ans = min(ans, abs(x1-a[j])+abs(x2-a[j])+t);
        p = lower_bound(b.begin(), b.end(), x1) - b.begin();
        t = (abs(y1-y2)+v-1) / v;
        for(int j = p-1; j <= p+1; j ++) if(0 <= j && j < B) ans = min(ans, abs(x1-b[j])+abs(x2-b[j])+t);
        cout << ans << endl;
    }
}