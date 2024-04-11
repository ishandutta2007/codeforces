#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n;
vpii od;
vpii ev;
pii rng1[3*MN];
pii rng2[3*MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        int x, y;
        cin >> x >> y;
        x += 100000; y += 100000;
        if((x+y)%2){
            od.pb({x+y, x-y});
        } else{
            ev.pb({x+y+1, x-y+1});
        }
    }

    ll sm = 0;

    F0R(_, 2){
        sort(od.begin(), od.end());

        int cur = 0;
        int l=INF, r=-INF;
        for(int i=0; i<=MN*4; i+=2){
            while(cur < od.size() && od[cur].f < i){
                l = min(l, od[cur].s); r=max(r, od[cur].s);
                ++cur;
            }
            rng1[i/2] = {l+1, r-1};
        }
        cur = od.size()-1; l=INF; r=-INF;
        for(int i=MN*4; i>=0; i-=2){
            while(cur >= 0 && od[cur].f > i){
                l = min(l, od[cur].s); r=max(r, od[cur].s);
                --cur;
            }
            rng2[i/2] = {l+1, r-1};
        }

        FOR(i, 0, MN*2){
            int l = max(rng1[i].f, rng2[i].f);
            int r = min(rng1[i].s, rng2[i].s);
            if(r < l) continue;
            sm += (r-l)/2+1;
        }

        swap(od, ev);
    }
    cout << sm << "\n";
    
    return 0;
}