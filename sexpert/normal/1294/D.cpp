#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 4e5 + 10;
int cnt[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q, x, cur = 0;
    cin >> q >> x;
    for(int i = 0; i < q; i++) {
        int y;
        cin >> y;
        cnt[y % x]++;
        while(cnt[cur % x]) {
            cnt[cur % x]--;
            cur++;
        }
        cout << cur << '\n';
    }
}