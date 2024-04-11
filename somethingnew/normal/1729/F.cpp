#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double fr;
typedef string str;    
typedef pair<ll, ll> node;
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define for0(i, n) for (ll i = 0; i < n; ++i)
#define for1(i, n) for (ll i = 1; i < n; ++i)
#define forn(i, a, n) for (int i = a; i < n; ++i)
#define forll(i, a, n) for (ll i = a; i < n; ++i)
#define lout(A) for (auto i : A) cout << i << " "; cout << endl;
#define lin(A) for (auto &i : A) cin >> i;
const ll INF = 1e9+7;
const fr eps = 1e-6;

ll v(ll l, ll r, vector<ll> &A) {
    ll ans = A[r];
    if (l)
        ans -= A[l-1];
    if (ans < 0)
        ans += 9;
    return ans;
}

int main() {
    ll qq;
    cin >> qq;
    while (qq--) {
        str s;
        ll w, m, n;
        cin >> s >> w >> m;
        n = s.size();
        vector<ll> Nin(n, (s[0] - '0') % 9), Nin2(n, -1);
        for1 (i, n)
            Nin[i] = (Nin[i-1] + s[i] - '0') % 9;
        Nin2[0] = Nin[w-1];
        for (ll i = 1; i+w-1 < n; ++i)
            Nin2[i] = (9 + Nin[i+w-1] - Nin[i-1]) % 9;
        vector<ll> Niners(9, -1), Niners2(9, -1);
        for0 (i, n-w+1) {
            if (Niners[Nin2[i]] == -1)
                Niners[Nin2[i]] = i;
            else if (Niners2[Nin2[i]] == -1)
                Niners2[Nin2[i]] = i;
        }
        /*   
        lout(Nin);
        lout(Nin2);
        lout(Niners);
        cout << endl;*/
        
        for0 (qqq, m) {
            node ans = {1e9, 1e9};
            ll l, r, k;
            cin >> l >> r >> k;
            --l, --r;
            ll j = v(l, r, Nin);
            for0 (i, 9) {
                if (Niners[i] > -1) {
                    ll b = (99 + k - j * i) % 9;
                    //cout << i << " * " << j << " + " << b << " = " << k << endl;
                    if (b != i && Niners[b] > -1 && ans.F > Niners[i])
                        ans = {Niners[i], Niners[b]};
                    else if (b == i && Niners2[b] > -1 && ans.F > Niners[i])
                        ans = {Niners[i], Niners2[b]};
                }
            }
            if (ans.F == 1e9)
                cout << -1 << ' ' << -1 << endl;
            else
                cout << ans.F+1 << ' ' << ans.S+1 << endl;
        }
    }
}