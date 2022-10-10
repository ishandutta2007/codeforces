#include <bits/stdc++.h>
using namespace std;

int numDestroyed[100000];
pair<int, int> beacon[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> beacon[i].first >> beacon[i].second;

    sort(beacon, beacon + n);

    numDestroyed[0] = 0;
    for (int i=1; i<n; i++) {
        int l = 0, r = i;
        while (l < r) {
            int m = (l + r) / 2;
            if (beacon[m].first >= beacon[i].first - beacon[i].second)
                r = m;
            else
                l = m + 1;
        }
        if (l == 0)
            numDestroyed[i] = i;
        else
            numDestroyed[i] = i - l + numDestroyed[l-1];
    }

    int ret = n;
    for (int i=0; i<n; i++)
        ret = min(ret, numDestroyed[i] + n - i - 1);

    cout << ret << "\n";

    return 0;
}