#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;

int n;
int a[N];
ll res[N], in[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int k = 1; k < n; k++) {
        for(int i = 1, j = 0; i <= k - 1; i = j + 1) {
            j = (k-1) / ((k-1) / i);
            if(a[(k-1)/i] > a[k]) in[i] ++, in[j+1] --;
        }
        if(a[0] > a[k]) in[k] ++, in[n]--;
    }

    ll cur = 0;
    for(int i = 1; i <= n - 1; i++) {
        cur += in[i];
        res[i] = cur;
    }
    for(int i = 1; i <= n - 1; i++) cout << res[i] << " ";
}