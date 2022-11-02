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
int n, q;
ll a[MN];
pll qs[MN]; //-1 = set
ll mns[MN];
ll ans[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
    }
    cin >> q;
    F0R(i, q){
        int c;
        cin >> c;
        if(c == 1){
            cin >> qs[i].f >> qs[i].s;
        } else{
            cin >> qs[i].s;
            qs[i].f = -1;
        }
    }
    memset(ans, -1, sizeof ans);
    RFOR(i, q-1, 0){
        mns[i] = mns[i+1];
        if(qs[i].f == -1) mns[i] = max(mns[i], qs[i].s);
        else{
            if(ans[qs[i].f] != -1) continue;
            ans[qs[i].f] = max(qs[i].s, mns[i]);
        }
    }
    FOR(i, 1, n){
        if(ans[i] == -1) ans[i] = max(a[i], mns[0]);
        cout << ans[i] << " ";
    }

    return 0;
}