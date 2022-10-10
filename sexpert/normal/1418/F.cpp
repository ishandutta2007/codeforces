#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;
int BIT[2 * MAXN];
vector<int> divs[2 * MAXN];

void upd(int p, int v) {
    for(; p < 2 * MAXN; p += (p & -p))
        BIT[p] += v;
}

int sum(int p) {
    int res = 0;
    for(; p; p -= (p & -p))
        res += BIT[p];
    return res;
}

int find(int l, int r) {
    if(l > r)
        return -1;
    int le = sum(l - 1);
    if(sum(r) == le)
        return -1;
    int x = 0, cur = 0;
    for(int k = 19; k >= 0; k--) {
        if(x + (1 << k) < 2 * MAXN && cur + BIT[x + (1 << k)] <= le) {
            x += (1 << k);
            cur += BIT[x];
        }
    }
    return x + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    ll l, r;
    cin >> n >> m >> l >> r;
    int ctr = 0;
    for(int d = 1; d <= 2 * max(n, m); d++) {
        for(int j = d; j <= 2 * max(n, m); j += d) {
            divs[j].push_back(d);
            ctr++;
        }
    }
    //cout << ctr << '\n';
    int smol = n / 2;
    for(int x1 = 1; x1 <= smol; x1++) {
        ll lb = (l + x1 - 1)/x1, rb = min((ll)m, r/x1);
        if(lb > rb) {
            cout << "-1\n";
            continue;
        }
        if(rb > lb) {
            if(lb % 2 == 0)
                cout << x1 << " " << lb << " " << 2 * x1 << " " << lb/2 << '\n';
            else
                cout << x1 << " " << lb + 1 << " " << 2 * x1 << " " << (lb + 1) / 2 << '\n';
            continue;
        }
        if(lb % 2 == 0) {
            cout << x1 << " " << lb << " " << 2 * x1 << " " << lb/2 << '\n';
            continue;
        }
        bool good = false;

        ll x = x1 * lb;
        vector<ll> divs;
        for(ll d = 1; d * d <= x; d++) {
            if(x % d)
                continue;
            divs.push_back(d);
            divs.push_back(x / d);
        }

        for(auto d : divs) {
            if(d > x1 && d <= n) {
                cout << x1 << " " << lb << " " << d << " " << x / d << '\n';
                good = true;
                break;
            }
        }

        if(!good)
            cout << "-1\n";
    }

    int pl = 2 * m + 1, pr = 2 * m;
    
    //cout << "end of small\n";
    for(int x1 = smol + 1; x1 <= n; x1++) {
        ll lb = (l + x1 - 1)/x1, rb = min((ll)m, r/x1);
        //cout << lb << " " << rb << '\n';
        while(pl > lb) {
            pl--;
            for(auto &d : divs[pl]) {
                //cout << "add " << d << '\n';
                upd(d, 1);
            }
        }
        while(pr > rb) {
            for(auto &d : divs[pr]) {
                //cout << "remove " << d << '\n';
                upd(d, -1);
            }
            pr--;
        }
        if(lb > rb) {
            cout << "-1\n";
            continue;
        }
        bool good = false;
        for(auto &d : divs[x1]) {
            ll r = x1 / d;
            //cout << "searching s between " << r + 1 << " and " << n / d << '\n';
            int s = find(r + 1, n / d);
            if(s == -1)
                continue;
            good = true;
            ll y1 = s * ((lb + s - 1)/s);
            cout << d*r << " " << y1 << " " << d * s << " " << y1 * r / s << '\n';
            break;
        }
        if(!good) {
            cout << "-1\n";
            continue;
        }
    }
}