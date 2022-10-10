#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;
int cnt[MAXN], c2, c4;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for(int i = 1; i < MAXN; i++) {
        c2 += cnt[i] / 2;
        c4 += cnt[i] / 4;
    }
    int q;
    cin >> q;
    while(q--) {
        char c;
        int x;
        cin >> c >> x;
        c2 -= cnt[x] / 2;
        c4 -= cnt[x] / 4;
        if(c == '+')
            cnt[x]++;
        else
            cnt[x]--;
        c2 += cnt[x] / 2;
        c4 += cnt[x] / 4;
        cout << ((c4 && c2 >= 4) ? "YES" : "NO") << '\n';
    }
}