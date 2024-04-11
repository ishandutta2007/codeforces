#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    long long ans = 0;
    int b = 1e9 + 13;
    for(int i = n - 1; i >= 0; i--){
        int c = max(0,  min(a[i], b - 1));
        ans += c;
        b = c;
    }

    cout << ans;
}