#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1234;
const int INF = 1e9;

int a0 = -1, a1 = -1, a10 = -1, a11 = -1, a100 = -1;
int n, x;

int main() {

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) a0 = 0;
        if (x < 10 && x > 0) a1 = x;
        if (x % 10 == 0 && x > 0 && x < 100) a10 = x;
        if (x % 10 && x > 9 && x < 100) a11 = x;
        if (x == 100) a100 = 100;
    }

    vector <int> ans;
    if (a0 != -1)
        ans.push_back(a0);
    if (a100 != -1)
        ans.push_back(a100);
    if (a10 != -1)
        ans.push_back(a10);
    if (a1 != -1)
        ans.push_back(a1);
    if (a11 != -1 && a10 == -1 && a1 == -1)
        ans.push_back(a11);

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    //while(true);
}