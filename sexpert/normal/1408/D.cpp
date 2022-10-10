#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int, 2>;

const int BIG = 1e6 + 10;
int res[BIG];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<ii> A(n), B(m);

    for(auto &[x, y] : A)
        cin >> x >> y;

    for(auto &[x, y] : B)
        cin >> x >> y;

    sort(B.begin(), B.end());

    vector<ii> tmp;
    for(auto p : B) {
        while(tmp.size() && p[1] >= tmp.back()[1])
            tmp.pop_back();
        tmp.push_back(p);
    }

    B = tmp;
    B.push_back({1000*1000 + 1, -1});
    //cout << tmp.size() << endl;
    //for(auto &[x, y] : B)
    //    cout << x << " " << y << endl;

    fill(res, res + BIG, -1);
    m = B.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(B[j][0] >= A[i][0])
                res[B[j][0] - A[i][0]] = max(res[B[j][0] - A[i][0]], B[j][1] - A[i][1]);
        }
    }

    int ans = 1e9;
    int mn = -1;
    for(int i = 1000*1000 + 1; i >= 0; i--) {
        mn = max(mn, res[i]);
        ans = min(ans, i + mn + 1);
    }

    cout << ans << '\n';
}