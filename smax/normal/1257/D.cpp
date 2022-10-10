#include <bits/stdc++.h>
using namespace std;

int a[200000], maxPow[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> a[i];

        for (int i=1; i<=n; i++)
            maxPow[i] = 0;

        int m;
        cin >> m;
        for (int i=0; i<m; i++) {
            int p, s;
            cin >> p >> s;
            maxPow[s] = max(maxPow[s], p);
        }
        for (int i=n-1; i>0; i--)
            maxPow[i] = max(maxPow[i], maxPow[i+1]);

        int i = 0, ret = 1, cnt = 0, maxMonster = 0;
        bool solExists = true;
        while (i < n && solExists) {
            maxMonster = max(maxMonster, a[i]);
            if (maxPow[cnt+1] < maxMonster) {
                if (cnt == 0)
                    solExists = false;
                maxMonster = a[i];
                cnt = 0;
                ret++;
            } else {
                cnt++;
                i++;
            }
        }

        cout << (solExists ? ret : -1) << "\n";
    }

    return 0;
}