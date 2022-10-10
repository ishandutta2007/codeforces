#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
int gol[MAXN], gor[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    for(int i = 0; i < n; i++) {
        if(i && v[i] > v[i - 1])
            gol[i] = gol[i - 1];
        else
            gol[i] = i;
        ans = max(ans, i - gol[i] + 1);
    }
    for(int i = n - 1; i >= 0; i--) {
        if(i < n - 1 && v[i] < v[i + 1])
            gor[i] = gor[i + 1];
        else
            gor[i] = i;
        ans = max(ans, gor[i] - i + 1);
    }
    for(int i = 1; i < n - 1; i++) {
        if(v[i - 1] < v[i + 1])
            ans = max(ans, gor[i + 1] - gol[i - 1]);
    }
    cout << ans << '\n';
}