#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, k;
int cnt[N];
int cnt0, cnt1;
int res = 0, rem = 0;

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int a; cin >> a; cnt[a]++;
    }
    for(int i = 1; i <= k; i++) {
        res += cnt[i] / 2 * 2;
        rem += cnt[i] % 2;
    }
    while(rem > 0) res++, rem -= 2;
    cout << res << endl;
}