#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;
const ll MOD = 998244353;
int n;
ll a[MAXN], su[MAXN][2];

struct node {
    int l, r;
    ll S[2];
    node *left, *right;

    node(int _l, int _r) : l(_l), r(_r) {
        if(l == r) {
            S[0] = S[1] = 0;
            S[l % 2] += a[l];
        }
        else {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
            S[0] = left->S[0] + right->S[0];
            S[1] = left->S[1] + right->S[1];
        }
    }

    int find(ll bound, int ty) {
        if(l == r) {
            if(S[ty] > bound)
                return l - 1;
            return l;
        }
        if(left->S[ty] >= bound)
            return left->find(bound, ty);
        bound -= left->S[ty];
        return right->find(bound, ty);
    }
};

void solve() {
    ll tar = 0, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        su[i][0] = su[i - 1][0];
        su[i][1] = su[i - 1][1];
        cin >> a[i];
        tar += a[i];
        su[i][i % 2] += a[i];
    }
    tar = (tar - 1)/2;
    if(n == 1) {
        cout << "1\n";
        return;
    }
    if(n == 2) {
        int ans = 1;
        if(a[1] < tar)
            ans++;
        if(a[2] < tar)
            ans++;
        cout << ans << '\n';
        return;
    }
    if(n <= 5) {
        for(int bm = 0; bm < (1 << n); bm++) {
            vector<int> p, c;
            for(int i = 1; i <= n; i++) {
                if((bm >> (i - 1)) & 1)
                    p.push_back(i);
                else
                    c.push_back(i);
            }
            bool good = true;
            ll tot = 0;
            for(int i = 1; i + 1 < p.size(); i++) {
                if(p[i + 1] - p[i] > p[i] - p[i - 1])
                    good = false;
            }
            for(int i = 1; i + 1 < c.size(); i++) {
                if(c[i + 1] - c[i] < c[i] - c[i - 1])
                    good = false;
            }
            for(auto &i : c)
                tot += a[i];
            if(tot > tar)
                good = false;

            if(good)
                ans++;
        }
        cout << ans << '\n';
        return;
    }
    // PP
    ll cur = 0;
    ans = 1;
    for(int i = n; i >= 3; i--) {
        cur += a[i];
        if(cur <= tar)
            ans++;
        else
            break;
    }

    //cerr << ans << '\n';

    node tree(0, n);
    //CC, no C at end
    cur = a[1] + a[2];
    int ri = tree.find(tar - cur + su[2][0], 0);
    //cerr << "2 " << cur << " " << tar - cur + su[2][0] << " " << ri << '\n';
    if(cur <= tar)
        ans++;
    if(ri == n)
        ri--;
    if(ri % 2)
        ri--;
    if(ri > 2)
        ans += (ri - 2)/2;
    //cerr << ans << '\n';
    for(int i = 3; i < n; i++) {
        cur += a[i];
        int ri = tree.find(tar - cur + su[i][i % 2], i % 2);
        //cerr << i << " " << cur << " " << tar - cur + su[i][i % 2] << " " << ri << '\n';
        if(cur <= tar)
            ans++;
        if(ri == n)
            ri--;
        if(ri % 2 != i % 2)
            ri--;
        if(ri >i)
            ans += (ri - i)/2;
    }

    //cerr << ans << '\n';

    //CC, C at the end
    cur = a[1] + a[2] + a[n];
    ri = tree.find(tar - cur + su[2][0], 0);
    if(cur <= tar)
        ans++;
    //cerr << "2 " << cur << " " << tar - cur + su[2][0] << " " << ri << '\n';
    while(ri >= n - 1)
        ri--;
    if(ri % 2)
        ri--;
    if(ri > 2)
        ans += (ri - 2)/2;
    for(int i = 3; i < n - 1; i++) {
        cur += a[i];
        if(cur <= tar)
            ans++;
        int ri = tree.find(tar - cur + su[i][i % 2], i % 2);
        //cerr << i << " " << cur << " " << tar - cur + su[i][i % 2] << " " << ri << '\n';
        while(ri >= n - 1)
            ri--;
        if(ri % 2 != i % 2)
            ri--;
        if(ri > i)
            ans += (ri - i)/2;
    }

    // CP
    cur = a[1];
    if(cur <= tar)
        ans++;
    if(cur + a[n] <= tar)
        ans++;
    for(int i = 3; i < n; i += 2) {
        cur += a[i];
        if(cur <= tar)
            ans++;
        if(i <= n - 2 && cur + a[n] <= tar)
            ans++;
    }

    //cerr << ans << '\n';

    //PC, no C at end
    cur = a[2];
    ri = tree.find(tar - cur + su[2][0], 0);
    //cerr << "2 " << cur << " " << tar - cur + su[2][0] << " " << ri << '\n';
    if(cur <= tar)
        ans++;
    if(ri == n)
        ri--;
    if(ri % 2)
        ri--;
    if(ri > 2)
        ans += (ri - 2)/2;
    //cerr << ans << '\n';
    for(int i = 3; i < n; i++) {
        cur += a[i];
        int ri = tree.find(tar - cur + su[i][i % 2], i % 2);
        //cerr << i << " " << cur << " " << tar - cur + su[i][i % 2] << " " << ri << '\n';
        if(cur <= tar)
            ans++;
        if(ri == n)
            ri--;
        if(ri % 2 != i % 2)
            ri--;
        if(ri >i)
            ans += (ri - i)/2;
    }

    //cerr << ans << '\n';

    //PC, C at the end
    cur = a[2] + a[n];
    ri = tree.find(tar - cur + su[2][0], 0);
    if(cur <= tar)
        ans++;
    //cerr << "2 " << cur << " " << tar - cur + su[2][0] << " " << ri << '\n';
    while(ri >= n - 1)
        ri--;
    if(ri % 2)
        ri--;
    if(ri > 2)
        ans += (ri - 2)/2;
    for(int i = 3; i < n - 1; i++) {
        cur += a[i];
        if(cur <= tar)
            ans++;
        int ri = tree.find(tar - cur + su[i][i % 2], i % 2);
        //cerr << i << " " << cur << " " << tar - cur + su[i][i % 2] << " " << ri << '\n';
        while(ri >= n - 1)
            ri--;
        if(ri % 2 != i % 2)
            ri--;
        if(ri > i)
            ans += (ri - i)/2;
    }

    cur = 0;
    for(int i = 2; i <= n; i++)
        cur += a[i];

    if(cur <= tar)
        ans++;

    cout << ans % MOD << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();    
}