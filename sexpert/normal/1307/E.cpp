#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAX = 5005;
int gr[MAX], tak[MAX];
ll cnt[MAX], mx[MAX];
vector<int> l, r, ff;
vector<pair<int, int>>fav[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    cin >> n >> c;
    for(int i = 1; i <= n; i++)
        cin >> gr[i];
    for(int i = 0; i < c; i++) {
        int f, h;
        cin >> f >> h;
        int hh = h;
        bool good = false;
        for(int i = 1; i <= n; i++) {
            if(gr[i] == f) {
                h--;
                if(h == 0) {
                    good = true;
                    l.push_back(i);
                    break;
                }
            }
        }
        if(!good)
            continue;
        h = hh;
        for(int i = n; i >= 1; i--) {
            if(gr[i] == f) {
                h--;
                if(h == 0) {
                    r.push_back(i);
                    break;
                }
            }
        }
        fav[f].push_back({l.back(), r.back()});
        ff.push_back(f);
    }
    c = l.size();
    //for(int i = 0; i < c; i++)
    //    cout << l[i] << " " << r[i] << '\n'; 
    if(c == 0) {
        cout << "0 1\n";
        return 0;
    }
    for(int i = 0; i < c; i++) {
        ll L = l[i], F = ff[i];
        //cout << L << " " << F << endl;
        ll tot = 1;
        ll cur = 1;
        for(int x = 1; x <= 5000; x++) {
            if(fav[x].empty())
                continue;
            //cout << "fav = " << x << endl;
            if(x == F) {
                ll c2 = 0;
                for(auto co : fav[x]) {
                    if(co.first == L)
                        continue;
                    c2 += (co.second > L);
                }
                if(c2 > 0) {
                    tot++;
                    cur = (cur * (ll)c2) % MOD;
                }
            }
            else {
                ll c1 = 0, c2 = 0, c12 = 0;
                for(auto co : fav[x]) {
                    if(co.first < L)
                        c1++;
                    if(co.second > L) {
                        if(co.first < L)
                            c12++;
                        c2++;
                    }
                }
                ll both = c1 * c2 - c12;
                if(c1 == 0 && c2 == 0)
                    continue;
                if(both > 0) {
                    tot += 2;
                    cur = (cur * both) % MOD;
                }
                else {
                    tot++;
                    cur = (cur * (ll)(c1 + c2)) % MOD;
                }
            }
        }
        mx[i] = tot;
        cnt[i] = cur;
    }
    ll tot = 0;
    ll cur = 1;
    for(int x = 1; x <= 5000; x++) {
        if(fav[x].empty())
            continue;
        tot++;
        cur = (cur * (ll)fav[x].size()) % MOD;
    }
    mx[c] = tot;
    cnt[c] = cur;
    ll M = 0;
    for(int i = 0; i <= c; i++)
        M = max(M, mx[i]);
    ll res = 0;
    for(int i = 0; i <= c; i++) {
        //cout << "* " << mx[i] << " " << cnt[i] << endl;
        if(mx[i] == M)
            res = (res + cnt[i]) % MOD;
    }
    cout << M << " " << res << '\n';
}