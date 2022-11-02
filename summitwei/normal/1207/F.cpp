#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 500005
#define MR 705
#define RT 700
int q;
ll a[MN];
ll sms[MR][MR];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> q;
    F0R(_, q){
        int c;
        cin >> c;
        if(c == 1){
            ll x, y;
            cin >> x >> y;
            a[x] += y;
            FOR(i, 1, RT){
                sms[i][x%i] += y;
            }
        } else{
            ll x, y;
            cin >> x >> y;
            if(x <= RT){
                cout << sms[x][y] << "\n";
            } else{
                ll res = 0;
                for(int i=y; i<=500000; i+=x){
                    res += a[i];
                }
                cout << res << "\n";
            }
        }
    }

    return 0;
}