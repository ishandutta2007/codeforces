#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
ll ans[155][10];

ll construct(ll fi, ll m, ll su) {
    string res;
    res += to_string(fi);
    su -= fi;
    if(su < 0)
        return INF;
    for(int i = 0; i < m - 1; i++) {
        res += '9';
        su -= 9;
        if(su < 0)
            return INF;
    }
    if(su >= 8) {
        res += '8';
        su -= 8;
    }
    while(su >= 9) {
        res += '9';
        su -= 9;
    }
    res += to_string(su);
    reverse(res.begin(), res.end());
    return stoll(res);
}

ll construct_pure(ll fi, ll su) {
    string res;
    res += to_string(fi);
    su -= fi;
    if(su < 0)
        return INF;
    while(su >= 9) {
        res += '9';
        su -= 9;
    }
    res += to_string(su);
    reverse(res.begin(), res.end());
    return stoll(res);
}

void check(ll n, ll m, ll k, ll c) {
    if(c == k) {
        ll tar = (n -  k*(k + 1)/2LL);
        if(tar < 0 || tar % (k + 1))
            return;
        ll a = tar/(k + 1);
        //if(n == 99 && k == 1)
        //    cout << n << " " << m << " " << k << " " << c << " " << a << endl;
        for(int j = 0; j <= 9 - c; j++)
            ans[n][k] = min(ans[n][k], construct_pure(j, a));
        return;
    }
    ll tar = (n + 9*m*(k - c) - k*(k + 1)/2);
    if(tar < 0 || tar % (k + 1))
        return;
    ll a = tar/(k + 1);
    ans[n][k] = min(ans[n][k], construct(10 - (c + 1), m, a));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int n = 1; n <= 150; n++) {
        int rem = n;
        string res;
        while(rem >= 9) {
            res += '9';
            rem -= 9;
        }
        res += to_string(rem);
        reverse(res.begin(), res.end());
        ans[n][0] = stoll(res);
    }
    //cout << ans[1][0] << endl;
    for(int k = 1; k < 10; k++) {
        //cout << "k = " << k << endl;
        for(int n = 1; n <= 150; n++) {
            ans[n][k] = INF;
            for(int c = 0; c <= k; c++) {
                for(int m = 1; m <= 17; m++) {
                    check(n, m, k, c);
                }
            }
        }
    }

    int t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        cout << (ans[n][k] == INF ? -1 : ans[n][k]) << '\n';
    }
}