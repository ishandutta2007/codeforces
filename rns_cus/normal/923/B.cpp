#include <bits/stdc++.h>
using namespace std;

#define N 100100

typedef long long ll;

int n, v[N], t[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &v[i]);
    for (int i = 1; i <= n; i ++) scanf("%d", &t[i]);
    priority_queue <ll, vector <ll>, greater <ll> > pq;
    ll sum = 0;
    for (int i = 1, sz = 0; i <= n; i ++) {
        pq.push(sum + v[i]); sz ++;
        sum += t[i];
        ll rlt = 0;
        while (!pq.empty()) {
            ll x = pq.top();
            if (x < sum) {
                pq.pop(); sz --;
                rlt += x - sum + t[i];
            }
            else break;
        }
        printf("%I64d ", rlt + 1ll * sz * t[i]);
    }
}