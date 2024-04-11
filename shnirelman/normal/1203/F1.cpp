#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

struct Project {
    int a, b, ind;

    Project() {};
};

bool cmp(const Project& a, const Project& b) {
    if(a.b >= 0 && b.b < 0)
        return true;

    if(a.b < 0 && b.b >= 0)
        return false;

    if(a.b >= 0)
        return a.a < b.a;
    else {
        return a.a + a.b > b.a + b.b;
    }
}

const int N = 113;

Project a[N];

int dp[N][N];

int main() {
    int n, r;
    cin >> n >> r;

//    vector<Project> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].a >> a[i].b;
        a[i].a = max(a[i].a, -a[i].b);
        a[i].ind = i;
    }

    sort(a, a + n, cmp);

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = -1;
    dp[0][0] = r;

    int ans = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(dp[i][j] >= 0) {
                if(dp[i][j] >= a[i].a) {
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i].b);
                }
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            }
        }

//    for(int i = 0; i <= n; i++) {
//        cout << i << " : ";
//        for(int j = 0; j <= n; j++)
//            cout << dp[i][j] << ' ';
//        cout << endl;
//    }

    cout << (dp[n][n] >= 0 ? "YES" : "NO");
    return 0;

    for(int i = n; i >= 0; i--)
        if(dp[n][i] >= 0) {
            cout << i;
            return 0;
        }


}