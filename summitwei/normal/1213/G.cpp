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
#define INF 0x3f3f3f3f
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
ll n, q;

/*struct Que{
    int tp;
    int val;
    pii ed;
    int loc;
};
Que ques[MN*2];*/
pair<ll, pll> ed[MN];
pll que[MN];

ll ans;

ll dsu[MN];
ll sz[MN];
ll fd(ll x){
    if(dsu[x] == x) return x;
    dsu[x] = fd(dsu[x]);
    return dsu[x];
}
void jn(ll x, ll y){
    x = fd(x); y = fd(y);
    if(x == y) return;

    if(sz[x] < sz[y]) swap(x, y);
    /*ans -= c2(sz[x]);
    ans -= c2(sz[y]);*/
    ans += 1LL*sz[x]*sz[y];
    dsu[y] = x;
    sz[x] += sz[y];
    //ans += c2(sz[x]);
}

ll rec[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    F0R(i, n-1){
        cin >> ed[i].s.f >> ed[i].s.s >> ed[i].f;
    }
    F0R(i, q){
        que[i].s = i;
        cin >> que[i].f;
    }
    sort(ed, ed+n-1);
    sort(que, que+q);

    FOR(i, 1, n){
        dsu[i] = i;
        sz[i] = 1;
    }

    ll cur = 0;
    F0R(i, q){
        while(cur < n && ed[cur].f <= que[i].f){
            jn(ed[cur].s.f, ed[cur].s.s);
            ++cur;
        }
        rec[que[i].s] = ans;
    }
    F0R(i, q){
        cout << rec[i] << " ";
    }

    return 0;
}