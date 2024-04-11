#include <bits/stdc++.h>
using namespace std;

int n,m;
int cnt[1005];

int main() {
    cin >> n >> m;
    int a;
    fill(cnt, cnt + 1005, 0);
    for(int i = 0; i < m; i++){
        cin >> a;
        cnt[a] ++;
    }
    int res = 1005;
    for(int i = 1; i <= n; i++){
        res = min(res, cnt[i]);
    }
    cout << res;
}