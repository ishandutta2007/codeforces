#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int M = (int)4e7 + 50, N = (int)4e5 + 50;

int n;
ll num[N];
ll x[N * 3];
ll res = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    for(int b = 0; b <= 27; b++) {

        ll cur_cnt = 0;
        for(int i = 0; i < n; i++) {
            x[i] = num[i] & ((1 << (b + 1)) - 1);
        }
        sort(x, x + n);
        for(int i = n; i < 2 * n; i++) x[i] = x[i - n] + (1LL << (b + 1));
        ll l = 2 * n;
        ll r = 2 * n;
        for(int i = 0; i < n; i++) {
            while(l - 1 >= 0 && x[l - 1] + x[i] >= (1LL << (b + 1)) + (1LL << b)) l--;
            while(r - 1 >= 0 && x[r - 1] + x[i] >= 2 * (1LL << (b + 1))) r--;
            cur_cnt += r - l;
        }
        for(int i = 0; i < n; i++) {
            if(((2 * num[i]) >> b) & 1) cur_cnt--;
        }
        assert(cur_cnt % 2 == 0);
        cur_cnt /= 2;
        if(cur_cnt % 2 == 1) res |= (1 << b);
    }
    cout << res << '\n';
}