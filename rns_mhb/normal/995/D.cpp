#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    long long sum = 0;
    vector <int> a(1<<n);
    for(int i = 0; i < (1<<n); i ++) cin >> a[i], sum += a[i];
    printf("%.10lf\n", 1.0 * sum / (1<<n));
    while(q --) {
        int x;
        cin >> x;
        sum -= a[x];
        cin >> a[x];
        sum += a[x];
        printf("%.10lf\n", 1.0 * sum / (1<<n));
    }
}