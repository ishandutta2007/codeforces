#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

typedef long long ll;
const int N = 26, F = 20;

int n, k;
ll S;
ll fac[N];
vector<ll> nums[2];
vector<ll> mds[2][N];

int get(vector<ll> &V, ll S) {
    return upper_bound(all(V), S) - lower_bound(all(V), S);
}

int main() {
    fac[0] = 1;
    for(int i = 1; i < F; i++) fac[i] = fac[i-1] * i;

    cin >> n >> k >> S;
    for(int i = 0; i < n; i++) {
        ll a; cin >> a;
        nums[i%2].push_back(a);
    }
    for(int t = 0; t < 2; t++) {
        int sz = nums[t].size();
        for(int mask = 0; mask < (1 << sz); mask++) {
            for(int ss = mask; ; ss = (ss - 1) & mask) {
                ll sum = 0, cnt = 0;
                for(int i = 0; i < sz; i++) {
                    if(!((1 << i) & mask)) continue;
                    if((1 << i) & ss) {
                        if(nums[t][i] >= F) {sum = -1; break; }
                        else {
                            sum += fac[nums[t][i]], cnt ++;
                        }
                    }
                    else sum += nums[t][i];
                }
                if(sum != -1 && cnt <= k && sum <= S) {
                    mds[t][cnt].push_back(sum);
                }

                if(ss == 0) break;
            }
        }
    }
    for(int i = 0; i < N; i++) sort(mds[1][i].begin(), mds[1][i].end());

    ll res = 0;
    for(int i = 0; i <= k; i++) {
        for(ll x : mds[0][i]) {
            for(int j = 0; j + i <= k; j++) {
                res += get(mds[1][j], S - x);
            }
        }
    }
    cout << res << endl;

}