#include <bits/stdc++.h>
using namespace std;

int cnt[1005];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int mx = 0;
    for(int i = 1; i <= 1000; i++)
        mx = max(mx, cnt[i]);
    cout << n - mx << endl;
}