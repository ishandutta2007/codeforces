#pragma GCC target("avx2")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>


using namespace std;


#define ll long long


const ll inf = 2e18;
const ll mod = 998244353;


const int mxn = 2e5;


struct dt{
    int tp;
    ll x;
    int ps;

    dt(int tp, ll x, int ps) : tp(tp), x(x), ps(ps) {}
};


bool operator<(const dt &d1, const dt &d2){
    if(d1.x != d2.x){
        return d1.x < d2.x;
    }
    return d1.tp < d2.tp;
}


int n;
vector<ll> a;
int m;
vector<ll> b;
vector<ll> x, y;
bitset<mxn> ok, aps;


int32_t main(){
    if(1){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int t;
    cin >> t;
    for(int i = 0; i < mxn; i += 1){
        aps[i] = 0;
    }
    while(t--){
        cin >> n;
        a.resize(n);
        for(int i = 0; i < n; i += 1){
            cin >> a[i];
        }
        cin >> m;
        b.resize(m);
        for(int i = 0; i < m; i += 1){
            cin >> b[i];
        }
        x.resize(n - 2);
        y.resize(m - 2);
        for(int i = 0; i < n - 2; i += 1){
            x[i] = a[i] + 2 * a[i + 1] + a[i + 2];
        }
        for( int i = 0; i < m - 2; i += 1){
            y[i] = b[i] + 2 * b[i + 1] + b[i + 2];
        }
        for(int i = 0; i + m <= n; i += 1){
            ok[i] = 1;
        }
        vector<dt> d;
        d.reserve(n + n + m);
        for(int i = 0; i < n - 2; i += 1){
            d.push_back(dt(0, x[i], i));
            d.push_back(dt(2, x[i] + 1, i));
        }
        for(int i = 0; i < m - 2; i += 1){
            d.push_back(dt(1, y[i], i));
        }

        sort(d.begin(), d.end());
        for(auto &f: d){
            if(f.tp == 0){
                aps[f.ps] = 1;
            } else if(f.tp == 1){
                auto flex = (aps >> f.ps);
                ok &= flex;
            } else if(f.tp == 2){
                aps[f.ps] = 0;
            }
        }
        vector<ll> p(n + 2);
        p[0] = 0;
        for(int i = 1; i <= n + 1; i += 1){
            p[i] = p[i - 1] + i - 1;
        }
        vector<int> ans(n, 0);
        bool fnd_ans = false;
        for(int i = 0; i + m <= n; i += 1){
            if (ok[i]) {
                ll t = i + 1;
                ll f = t / 2;
                ll c = a[i] - b[0];
                ll d = a[i + 1] - b[1];
                d = -d;
                c -= f * (f + 1);
                d -= f * (f + 1) + f + 1;
                if(c > 0 || d > 0 || c - d < 0 || c - d > t + 1){
                    continue;
                }
                ll cnt = c - d;
                ll l = p[cnt];
                ll r = p[t + 1] - p[t + 1 - cnt];
                if(!(l <= -c && -c <= r)){
                    continue;
                }
                fnd_ans = true;
                int mcnt = cnt;
                for(int j = 0; j <= i + 1; j += 1){
                    ll mt = i - j + 1;
                    if(mcnt > 0){
                        ll l = p[mcnt - 1];
                        ll r = p[mt] - p[mt - (mcnt - 1)];
                        if(l <= -(c + mt) && -(c + mt) <= r){
                            ans[j] = true;
                            c += mt;
                            d += mt + 1;
                            mcnt -= 1;
                        }
                    }
                    if(mt % 2 == 0){
                        ans[j] = !ans[j];
                    }
                }
                for(int j = 0; j + 3 <= m; j += 1){
                    if(x[i + j] + 1 == y[j]){
                        ans[i + j + 2] = 1;
                    }
                }
                break;
            }
        }
        if(fnd_ans){
            int ansc = 0;
            for(int i = 0; i < n; i += 1){
                if(ans[i]){
                    ansc += 1;
                }
            }
            cout << ansc << "\n";
            for(int i = 0; i < n; i += 1){
                if(ans[i]){
                    cout << i + 1 << " ";
                }
            }
            cout << "\n";
        } else{
            cout << -1 << "\n";
        }
    }
    return 0;
}