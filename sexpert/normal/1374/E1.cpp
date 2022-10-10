#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> lmao[4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int val, x, msk = 0;
        cin >> val >> x;
        msk += x;
        cin >> x;
        msk += 2*x;
        lmao[msk].push_back(val);
    }
    for(int i = 1; i <= 3; i++)
        sort(lmao[i].begin(), lmao[i].end());
    if(lmao[3].size() + min(lmao[1].size(), lmao[2].size()) < k) {
        cout << "-1\n";
        return 0;
    }
    int st = min(k, (int)lmao[3].size());
    int rem = k - st;
    int ans = 0;
    for(int i = 0; i < rem; i++) {
        ans += lmao[1][i];
        ans += lmao[2][i];
    }
    for(int i = 0; i < st; i++) {
        ans += lmao[3][i];
    }
    int bst = ans;
    while(st) {
        rem++;
        if(rem > lmao[1].size() || rem > lmao[2].size())
            break;
        ans += lmao[1][rem - 1];
        ans += lmao[2][rem - 1];
        st--;
        ans -= lmao[3][st];
        bst = min(bst, ans);
    }
    cout << bst << '\n';
}