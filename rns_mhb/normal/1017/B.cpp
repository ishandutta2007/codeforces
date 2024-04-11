#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    int x = 0, y = 0;
    for(int i = 0; i < n; i ++) {
        if(a[i] == '0') x ++;
        else y ++;
    }
    long long ans = 1ll * x * y;
    for(int i = 0; i < n; i ++) if(b[i] == '0') {
        if(a[i] == '0') x --;
        else y --;
    }
    ans -= 1ll * x * y;
    cout << ans << endl;
}