#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 5;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == -1)
            for(int j = 1; j <= i; j++)
                a[j] = 0;
    }
    priority_queue<int> pq;
    ll ans = 0;
    for(int i = n; i >= 1; i--) {
        pq.push(-a[i]);
        if((i&(i-1)) == 0) {
            ans -= pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
}