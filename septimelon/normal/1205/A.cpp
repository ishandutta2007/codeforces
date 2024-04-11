#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << '\n';
    vector<int> ans(2*n);
    int ind = 0;
    int v = 1;
    while (v <= 2*n) {
        ans[ind] = v;
        ans[ind + n] = v+1;
        v += 2;
        if (ind+1 >= n)
            break;
        ind++;
        ans[ind] = v+1;
        ans[ind + n] = v;
        v += 2;
        ind++;
    }
    for (int i = 0; i < 2 * n; i++)
        cout << ans[i] << " ";
    return 0;
}