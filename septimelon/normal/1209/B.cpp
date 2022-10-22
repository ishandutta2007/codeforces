#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> bur(500, 0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    bool now;
    for (int k = 0; k < n; k++) {
        if (s[k] == '1')
            now = true;
        else
            now = false;
        int nex = b[k];
        int cur = 0;
        while (cur < 500) {
            if (cur == nex) {
                nex += a[k];
                if (now)
                    now = false;
                else
                    now = true;
            }
            if (now)
                bur[cur]++;
            cur++;
        }
    }
    int maxb = 0;
    for (int i = 0; i < 500; i++) {
        //cout << i << " " << bur[i] << endl;
        maxb = max(maxb, bur[i]);
    }
    cout << maxb << endl;
    return 0;
}