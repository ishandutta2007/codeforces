#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ans[100010];

int main() {
    int n, k;
    cin >> n >> k;
    if(true) {
        int p = 1 + (n - k)/2;
        for(int i = 1; i < p; i++) ans[i] = 1;
        ans[p] = 0;
        for(int i = p + 1; i <= n; i++) ans[i] = ans[i - p];
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i];
    cout << endl;
}