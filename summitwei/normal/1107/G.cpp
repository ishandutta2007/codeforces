#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000000000LL
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
int n;
ll a;
ll c[MN];
ll d[MN];

ll lf[MN]; //when this is the left side
ll rt[MN];
ll all[MN];

pll difs[MN];

int dsu[MN];
int sz[MN];
int find(int x){
    if(x == dsu[x]) return x;
    dsu[x] = find(dsu[x]);
    return dsu[x];
}
ll unite(int x, int y, ll d){
    x = find(x);
    y = find(y);
    if(x == y) return 0;

    ll sum = lf[x] + rt[y] - d;
    
    ll l = max(lf[x] + all[y], lf[y]);
    ll r = max(rt[x], all[x] + rt[y]);
    ll s = all[x] + all[y];

    if(sz[x] < sz[y]) swap(x, y);

    dsu[y] = x;
    lf[x] = l;
    rt[x] = r;
    all[x] = s;
    sz[x] += sz[y];

    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a;
    ll ans = 0;
    F0R(i, n){
        cin >> d[i] >> c[i];
        lf[i] = a-c[i];
        rt[i] = a-c[i];
        all[i] = a-c[i];
        dsu[i] = i;
        ans = max(ans, a-c[i]);

        difs[i].s = i;
        if(i != 0){
            difs[i-1].f = d[i]-d[i-1];
        }
    }

    sort(difs, difs+n-1);
    //ll ans = 0;
    F0R(i, n-1){
        //cout << difs[i].s << " " << difs[i].f << "\n";
        ans = max(ans, unite(difs[i].s, difs[i].s+1, difs[i].f*difs[i].f));
    }

    cout << ans << "\n";

    return 0;
}