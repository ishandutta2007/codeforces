#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<long long> b(100005), ans(200005);
    cin >> n;
    for(int i = 0; i < n/2; i++)
        cin >> b[i];
    ans[0] = 0;
    ans[n - 1] = b[0];
    for(int i = 1; i < n/2; i++) {
        if(b[i] - ans[i - 1] <= ans[n - i]) {
            ans[i] = ans[i - 1];
            ans[n - i - 1] = b[i] - ans[i - 1];
        } else {
            ans[n - i - 1] = ans[n - i];
            ans[i] = b[i] - ans[n - i - 1];
        }
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}