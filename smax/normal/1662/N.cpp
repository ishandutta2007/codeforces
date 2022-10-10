#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define endl "\n"
// const int inf = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(n,0));
    vector<pi> loc(n*n);

    // vector<vector<int>> used(n,vector<int>(n,0));

    for(int x=0;x<n;x++) {
        for(int y=0;y<n;y++) {
            cin >> arr[x][y];
            loc[arr[x][y]-1] = mp(x,y);
        }
    }

    vector<int> rSum(n,0);
    vector<int> cSum(n,0);

    int ans = 0;
    for(int x=0;x<n*n;x++) {
        pi curr = loc[x];
        int a = rSum[curr.first];
        int b = cSum[curr.second];

        ans += a*(n-1-b) + b*(n-1-a);

        rSum[curr.first]++;
        cSum[curr.second]++;

    }

    cout << ans/2 << endl;

    return 0;
}