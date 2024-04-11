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

#define MN 300005
#define VAL 300000LL
ll m, a, b;

ll sm(ll x, ll y){ //x<y
    return (x+y)*(y-x+1)/2;
}

ll tims[MN];
ll vis[MN];
priority_queue<pll, vector<pll>, greater<pll> > q;
void bfs(ll mx){ //kinda dijk but whatever
    q.push(mp(0, 0));

    while(!q.empty()){
        pll top = q.top();
        q.pop();
        
        if(vis[top.s] != -1) continue;
        vis[top.s] = top.f;
        tims[top.f]++;
        //cout << top.s << " first visited w/ " << top.f << "\n";

        if(top.s >= b){
            q.push(mp(top.f, top.s-b));
        }
        if(top.s+a <= mx){
            q.push(mp(max(top.f, top.s+a), top.s+a));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> a >> b;
    ll tot = 0;

    //memset(tims, -1, sizeof tims);
    memset(vis, -1, sizeof vis);

    ll mxv = min(m, VAL);
    ll cur = 0;

    bfs(mxv);

    FOR(i, 0, mxv){
        cur += tims[i];
        //cout << i << " " << cur << "\n";
        tot += cur;
    }

    //cout << tot << "\n";

    ll gcd = __gcd(a, b);
    ll lb = mxv+1;
    while(lb <= m && lb % gcd != 0){
        tot += (1+lb/gcd);
        lb++;
    }
    ll rb = m;
    while(rb >= lb && (rb+1)%gcd != 0){
        tot += (1+rb/gcd);
        rb--;
    }

    if(lb > rb){
        cout << tot << "\n";
        return 0;
    }
    
    ll lf = (1+lb/gcd);
    ll rt = (1+rb/gcd);
    tot += (sm(lf, rt)*gcd);


    cout << tot << "\n";
    
    return 0;
}