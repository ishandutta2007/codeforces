#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 50, INF = (int)1e9 + 50;

int n, q;
int num[3 * N], rem[3 * N], cnt[3 * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        num[i + n] = num[i + 2 * n] = num[i];
    }
    while(q--) {
        ll mxsum; cin >> mxsum;
        ll sum = 0;
        int l = n;
        while(l >= 1 && sum + num[l-1] <= mxsum) {
            l--;
            sum += num[l];
        }
        int res = INF;
        for(int i = n; i < 2 * n; i++) {
            sum += num[i];
            while(sum > mxsum) sum -= num[l++];
            if(l <= n) {
                cnt[i] = 1, rem[i] = n - l;
            }
            else {
                cnt[i] = cnt[l-1] + 1;
                rem[i] = rem[l-1];
            }
//            cout << l << " " << i << endl;
            if(i - n + 1 + rem[i] >= n) res = min(res, cnt[i]);
        }
        cout << res << "\n";
    }

}