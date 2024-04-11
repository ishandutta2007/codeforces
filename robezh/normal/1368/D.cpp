#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

const int N = (int)2e5 + 50;

int n;
int a[N], cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int b = 0; b < 20; b++) cnt[b] += (a[i] >> b & 1);
    }
    ll res = 0;
    for(int i = 0; i < n; i++) {
        int cur = 0;
        for(int b = 0; b < 20; b++) {
            if(cnt[b]) {
                cnt[b]--;
                cur |= (1 << b);
            }
        }
        res += 1LL * cur * cur;
    }
    cout << res << endl;

}