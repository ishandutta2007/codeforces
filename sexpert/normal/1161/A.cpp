#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int fi[MAXN], la[MAXN];

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(k);
    for(auto &x : v) cin >> x;
    for(int i = 1; i <= n; i++)
        fi[i] = la[i] = -1;
    for(int i = 0; i < k; i++)
        la[v[i]] = i;
    for(int i = k - 1; i >= 0; i--)
        fi[v[i]] = i;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = max(1, i - 1); j <= min(n, i + 1); j++) {
            if(i == j) {
                if(fi[i] == -1)
                    ans++;
            }
            else {
                if(fi[i] == -1 || fi[i] == -1 || fi[i] > la[j])
                    ans++;
            }
        }
    }
    cout << ans << endl;
}