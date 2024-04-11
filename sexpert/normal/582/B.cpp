#include <bits/stdc++.h>
using namespace std;

int LIS[305], cnt[305];
int a[50005];

int main() {
    int n, T;
    cin >> n >> T;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = n + 1; i <= n*min(500, T); i++)
        a[i] = a[i - n];
    for(int i = 1; i <= n*min(500, T); i++) {
        int x = a[i];
        LIS[x]++;
        for(int j = 1; j < x; j++)
            LIS[x] = max(LIS[x], LIS[j] + 1);
    }
    int mx = 0;
    for(int i = 1; i <= 300; i++)
        mx = max(mx, LIS[i]);
    if(T <= 500) {
        cout << mx << endl;
        return 0;
    }
    int app = 0;
    for(int i = 1; i <= 300; i++)
        app = max(app, cnt[i]);
    cout << mx + (T - 500)*app << endl;
}