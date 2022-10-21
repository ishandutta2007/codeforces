#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 2005;

int n, m, k;
pii p[N];
int addsl[2 * N];

int getover(int l1, int r1, int l2, int r2) {
    return max(0, min(r1, r2) - max(l1, l2) + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    rep(i, 0, m) {
        cin >> p[i].first >> p[i].second; p[i].first--, p[i].second--;
    }
    int res = 0;
    for(int i = 0; i + k - 1 < n; i++){
        int sl = 0;
        fill(addsl, addsl + N, 0);
        int sum = 0;
        rep(j, 0, m) {
            if(p[j].first <= i || p[j].second <= i + k - 1) {
                sum += getover(i, i + k - 1, p[j].first, p[j].second);
            } else {
                int l0 = max(i, p[j].first - k), l1 = min(p[j].second - k + 1, p[j].first);
                int r1 = max(p[j].second - k + 1, p[j].first), r0 = l1 + r1 - l0;
                sum += getover(i, i + k - 1, p[j].first, p[j].second);
                addsl[l0]++;
                addsl[l1]--;
                addsl[r1]--;
                addsl[r0]++;
            }
        }
        rep(j, i, n) {
            res = max(res, sum);
            sl += addsl[j];
            sum += sl;
        }
    }
    cout << res << '\n';

}