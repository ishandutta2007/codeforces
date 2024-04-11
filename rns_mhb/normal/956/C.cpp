#include<bits/stdc++.h>
using namespace std;

#define N 100010

int a[N], b[N];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int mx = -1;
    for(int i = 1; i <= n; i ++) {
        if(a[i] > mx) {
            mx = a[i];
            b[i] = a[i]+1;
        }
        else b[i] = b[i-1];
    }
    for(int i = n-1; i >= 1; i --) b[i] = max(b[i], b[i+1]-1);
    long long ans = 0;
    for(int i = 1; i <= n; i ++) ans += b[i]-a[i]-1;
    cout << ans << endl;
}