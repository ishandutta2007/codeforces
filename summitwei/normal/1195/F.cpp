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

#define MN 100005
int n, q;
vector<pll> a[MN];
vector<pll> ree[MN];
map<pll, int> wtmoo;
vi orz[MN];
pair<pii, int> bruh[MN];
int geniosity[MN];
int no_u[3*MN];

void upd(int node, int a, int b, int i, int j, int val){
    //cout << node << " " << a << " " << b << " " << i << " " << j << "\n";
    if(a > j || b < i || b < a) return;
    if(i <= a && b <= j){
        no_u[node] += val;
        return;
    }
    upd(node*2, a, (a+b)/2, i, j, val);
    upd(node*2+1, 1+(a+b)/2, b, i, j, val);
    no_u[node] = no_u[node*2]+no_u[node*2+1];
}
int que(int node, int a, int b, int i, int j){
    //cout << node << " " << a << " " << b << " " << i << " " << j << "\n";
    if(a > j || b < i || b < a) return 0;
    if(i <= a && b <= j) return no_u[node];
    int q1 = que(node*2, a, (a+b)/2, i, j);
    int q2 = que(node*2+1, 1+(a+b)/2, b, i, j);
    return q1+q2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        int k;
        cin >> k;
        F0R(j, k){
            ll x, y;
            cin >> x >> y;
            a[i].pb({x, y});
            if(j == 0) continue;
            ll dx = a[i][j].f-a[i][j-1].f;
            ll dy = a[i][j].s-a[i][j-1].s;
            ll gcd = __gcd(dx, dy);
            dx /= abs(gcd);
            dy /= abs(gcd);
            ree[i].pb({dx, dy});
        }
        ll dx = a[i][0].f-a[i][k-1].f;
        ll dy = a[i][0].s-a[i][k-1].s;
        ll gcd = __gcd(dx, dy);
        dx /= abs(gcd);
        dy /= abs(gcd);
        ree[i].pb({dx, dy});
    }
    RFOR(i, n, 1){
        for(auto u : ree[i]){
            if(wtmoo[u] == 0){
                orz[i].pb(n+1);
            } else{
                orz[i].pb(wtmoo[u]);
            }
            wtmoo[u] = i;
        }
    }

    for(auto u : wtmoo){
        upd(1, 1, n+1, u.s, u.s, 1);
    }

    cin >> q;
    F0R(i, q){
        cin >> bruh[i].f.f >> bruh[i].f.s;
        bruh[i].s = i;
    }
    sort(bruh, bruh+q);
    int cur = 0;
    FOR(i, 1, n){
        while(cur < q && bruh[cur].f.f == i){
            int res = que(1, 1, n+1, bruh[cur].f.f, bruh[cur].f.s);
            geniosity[bruh[cur].s] = res;
            ++cur;
        }
        upd(1, 1, n+1, i, i, -a[i].size());
        for(auto u : orz[i]){
            upd(1, 1, n+1, u, u, 1);
        }
    }

    F0R(i, q){
        cout << geniosity[i] << "\n";
    }
    
    return 0;
}