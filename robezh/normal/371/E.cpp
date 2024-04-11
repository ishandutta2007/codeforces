#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e5 + 50;
typedef long long ll;
typedef pair<int, int> P;
const ll INF = (ll)9e18;

int n, k;
int x[N];
P p[N];
ll psum[N], sqsum[N];
ll res[N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        p[i].first = x[i];
        p[i].second = i;
    }
    sort(p, p + n);
    sort(x, x + n);
    cin >> k;
    k--;
    for(int i = n - 1; i >= 1; i--) x[i] -= x[i-1], x[i] = abs(x[i]);
    n--;
    for(int i = 1; i <= n; i++) psum[i] = psum[i-1] + x[i];
    for(int i = 2; i <= k; i++) sqsum[k] += 1LL * x[i] * 2 * i;
    for(int i = k + 1; i <= n; i++) {
        int l = i - (k - 1);
        sqsum[i] = sqsum[i-1] - 1LL * 2 * 2 * x[l] + 1LL * k * 2 * x[i] - 2 * (psum[i-1] - psum[l]);
    }
    for(int i = 1; i <= k; i++) {
        res[k] += 1LL * i * (k + 1 - i) * x[i];
    }
    for(int i = k + 1; i <= n; i++) {
        res[i] = res[i-1] + 1LL * x[i] * k - 1LL * x[i-k] * k
                + sqsum[i-1] - (psum[i-1] - psum[i-k]) * (k + 2);
    }

    ll fres = INF;
    int fid = -1;
    for(int i = k; i <= n; i++) {
        if(res[i] < fres) {
            fres = res[i];
            fid = i;
        }
    }
    for(int i = fid - k; i <= fid; i++) cout << p[i].second + 1 << " ";
    cout << endl;

}