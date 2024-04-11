#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> a, int j) {
    if (a.empty() || j < 0)
        return 0;

    vector<int> v1, v2;
    for (int i : a) {
        if (i & (1 << j))
            v1.push_back(i);
        else
            v2.push_back(i);
    }

    if (v1.empty())
        return solve(v2, j - 1);
    if (v2.empty())
        return solve(v1, j - 1);
    return min(solve(v1, j - 1), solve(v2, j - 1)) + (1 << j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    cout << solve(a, 30) << "\n";

    return 0;
}