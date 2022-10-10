#include <bits/stdc++.h>
using namespace std;

vector<int> f[10] = {{}, {}, {2}, {3}, {3, 2, 2}, {5}, {5, 3}, {7}, {7, 2, 2, 2}, {7, 3, 3, 2}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    string a;
    cin >> n >> a;

    vector<int> ret;
    for (char c : a)
        for (int i : f[c-'0'])
            ret.push_back(i);

    sort(ret.begin(), ret.end(), greater<int>());
    for (int i : ret)
        cout << i;
    cout << "\n";

    return 0;
}