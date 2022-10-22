#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n + 1, 0);
    vector <ll> mint(n + 1, 0);
    vector <ll> all(n + 1, 0);
    ll z = (1LL << k) - 1;
    map <ll, ll> cnt;
    cnt[0] = 1;
    ll sum = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] ^= a[i - 1];
        //cout << a[i] << " ";
        if (cnt[a[i]] > cnt[z - a[i]]) {
            sum += cnt[z - a[i]];
            cnt[z - a[i]]++;
        } else {
            sum += cnt[a[i]];
            cnt[a[i]]++;
        }
    }
    //cout << "\n";
    cout << n * (n + 1) / 2 - sum;;
}