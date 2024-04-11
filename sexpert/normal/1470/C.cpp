#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int qs = 0, n, k, p;
const int MAXN = 1e5 + 10;
ll v[MAXN], nx[MAXN];

void step() {
    for(int i = 1; i <= n; i++) {
        int ri = (i < n ? i + 1 : 1), le = (i > 1 ? i - 1 : n);
        if(i == p)
            nx[ri] += v[i];
        else {
            nx[ri] += (v[i] + 1)/2;
            nx[le] += (v[i])/2;
        }
    }
    for(int i = 1; i <= n; i++) {
        v[i] = nx[i];
        nx[i] = 0;
    }
}

ll fask(int q) {
   // cout << "asked " << q << '\n';
    //for(int i = 1; i <= n; i++)
    //    cout << v[i] << " ";
    //cout << '\n';
    while(q > n)
        q -= n;
    ll ans = v[q];
    step();
    return ans;
}

ll ask(int q) {
    //return fask(q);
    while(q > n)
        q -= n;
    cout << "? " << q << '\n';
    cout.flush();
    qs++;
    ll x;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;// >> p;
    for(int i = 1; i <= n; i++)
        v[i] = k;
    int pv = 0, step = 1, cur = 1;
    int l = 0, r = 0;
    vector<int> asked;
    while(cur <= n) {
        ll x = ask(cur);
        asked.push_back(cur);
        if(x != k) {
            l = cur - step + 1;
            r = cur + step - 1;
            break;
        }
        cur += 2*step;
        step++;
        pv = cur;
    }
    if(l == 0) {
        ll x = ask(cur);
        if(x != k) {
            l = cur - step + 1;
            r = cur + step - 1;
        }
    }
    vector<int> cand;
    if(l == 0)
        cand = asked;
    else {
        ll pv = -1;
        for(int x = l; x <= r + 1; x++) {
            ll c = ask(x);
            if(pv == k && c > k) {
                int y = x - 1;
            while(y > n)
                y -= n;
            cout << "! " << y << '\n';
            cout.flush();
            exit(0);
            }
            pv = c;
        }
    }
    for(auto x : cand) {
        if(ask(x + 1) > k) {
            int y = x;
            while(y > n)
                y -= n;
            cout << "! " << y << '\n';
            cout.flush();
            exit(0);
        }
    }
}