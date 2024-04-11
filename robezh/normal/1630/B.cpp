#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

int n, k;
int a[N], cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        fill(cnt, cnt + n + 1, 0);
        rep(i, 0, n) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        int r = 1, sum = 0;
        int mnl = 1, mnr = n;
        rep(i, 1, n + 1) {
            while(r <= n && sum < n - sum + k) {
                sum += cnt[r++];
            }
            if(sum >= n - sum + k && r - i < mnr - mnl + 1) {
                mnr = r - 1;
                mnl = i;
            }
            sum -= cnt[i];
        }
        cout << mnl << " " << mnr << '\n';
        int c = 0, la = 0;
        int ct = 0;
        rep(i, 0, n) {
            if(mnl <= a[i] && a[i] <= mnr) c++;
            else c--;

            if(c > 0 && ct < k - 1) {
                cout << la + 1 << " " << i + 1 << '\n';
                la = i + 1;
                c = 0;
                ct++;
            }
        }
        cout << la + 1 << " " << n << '\n';
    }
}