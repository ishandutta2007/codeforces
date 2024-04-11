#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n, m, k;
ll ta, tb;
ll a[MN];
ll b[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> ta >> tb >> k;
    F0R(i, n) cin >> a[i];
    F0R(i, m) cin >> b[i];

    ll mn = -1;

    F0R(i, min(k+1, n)){
        ll et = a[i]+ta;
        int ind = lower_bound(b, b+m, et) - b;
        int rl = ind+max(0, k-i);
        if(rl < m) mn = max(mn, b[rl]+tb);
        else{
            mn = INF*10LL;
            break;
        }
        //cout << ind << " " << rl << "\n";
    }

    if(mn == INF*10LL || k >= n) cout << "-1\n";
    else cout << mn << "\n";

    return 0;
}