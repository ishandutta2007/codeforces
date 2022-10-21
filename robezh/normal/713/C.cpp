#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;
int n, a[N];
ll ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], a[i] -= i;

    priority_queue<int> pque;
    for(int i = 0; i < n; i++) {
        pque.push(a[i]);
        pque.push(a[i]);
        ans += pque.top() - a[i];;
        pque.pop();
    }
    cout << ans << '\n';

}