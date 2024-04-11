#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    for (int cf = 1; cf <= k + 1; ++cf) {
        cout << "?";
        for (int i = 1; i <= k + 1; ++i) {
            if (i == cf) {
                continue;
            }
            cout << " " << i;
        }
        cout << endl;
        int pos, a;
        cin >> pos >> a;
        ans.push_back(a);
    }
    sort(ans.begin(), ans.end());
    int cmin = 0;
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] != ans[0]) {
            ++cmin;
        }
    }
    cout << "! " << cmin << endl;
    return 0;
}