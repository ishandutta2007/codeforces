#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 504;

bool u[N][N];
bool ez[N];

int n, k;
int a[N];
int s2;

int main() {
    init();

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    u[0][0] = true;

    for (int i = 0; i < n; i++)
        for (int sum = k - a[i]; sum >= 0; sum--)
            for (int j = sum; j >= 0; j--)
                if (u[sum][j]) {
                    u[sum + a[i]][j + a[i]]  = true;
                    u[sum + a[i]][j] = true;
                    u[sum + a[i]][0] = true;
                    u[sum + a[i]][a[i]] = true;
                }

    vector <int> ans;
    for (int i = 0; i <= k; i++)
        if (u[k][i])
            ans.push_back(i);

    cout << ans.size() << "\n";
    for (int w: ans)
        cout << w << " ";

    return 0;
}