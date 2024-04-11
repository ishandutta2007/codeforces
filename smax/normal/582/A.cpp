#include <bits/stdc++.h>
using namespace std;

map<int, int, greater<int>> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n*n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    vector<int> ret;
    for (auto &p : cnt)
        while (p.second) {
            p.second--;
            for (int i : ret)
                cnt[__gcd(i, p.first)] -= 2;
            ret.push_back(p.first);
        }

    for (int i : ret)
        cout << i << " ";
    cout << "\n";

    return 0;
}