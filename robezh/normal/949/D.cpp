#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

int n, d, b;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> d >> b;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res1 = 0, r = 0;
    int sum = 0;
    for(int i = 0; i < (n + 1) / 2; i++) {
        while(r < n && r <= i + 1LL * (i + 1) * d) sum += a[r++];
        if(sum < b) res1++;
        else sum -= b;
    }
    int res2 = 0, l = n - 1;
    sum = 0;
    for(int i = n - 1; i >= (n + 1) / 2; i--) {
        while(l >= 0 && l >= i - 1LL * (n - i) * d) sum += a[l--];
        if(sum < b) res2++;
        else sum -= b;
    }
    cout << max(res1, res2) << endl;
}