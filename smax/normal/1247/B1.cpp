#include <bits/stdc++.h>
using namespace std;

int a[200000], cnt[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, k, d;
        cin >> n >> k >> d;
        for (int i=0; i<n; i++)
            cin >> a[i];

        memset(cnt, 0, sizeof(cnt));
        int i = 0, ret = INT_MAX, num = 0;
        for (int j=0; j<n; j++) {
            if (cnt[a[j]-1] == 0)
                num++;
            cnt[a[j]-1]++;
            while (j - i + 1 > d) {
                cnt[a[i]-1]--;
                if (cnt[a[i]-1] == 0)
                    num--;
                i++;
            }
            if (j - i + 1 == d)
                ret = min(ret, num);
        }

        cout << ret << "\n";
    }

    return 0;
}