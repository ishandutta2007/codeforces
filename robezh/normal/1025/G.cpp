#include <bits/stdc++.h>
using namespace std;

const int N = 505, mod = (int)1e9 + 7;

int n;
int a[N], cnt[N];
int pw[N];

int main() {
    pw[0] = 0;
    for(int i = 1; i < N; i++) pw[i] = (pw[i-1] * 2 + 1) % mod;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] != -1) cnt[--a[i]] ++;
    }
    int res = pw[n-1];
    for(int i = 0; i < n; i++) res = (res - pw[cnt[i]]) % mod;
    cout << (res % mod + mod) % mod << endl;
}