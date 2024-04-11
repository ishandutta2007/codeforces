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
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n, w, h;
pair<int, pii> dan[MN];
vector<pair<pii, int> > dia[2*MN];
vpii cur;
pii ans[MN];

bool comp(pair<pii, int> a, pair<pii, int> b){
    if(a.f.f != b.f.f) return a.f.f > b.f.f;
    if(a.f.f == 1) return a.f.s < b.f.s;
    else return a.f.s > b.f.s;
}
bool comp2(pii a, pii b){
    if(a.f != b.f) return a.f < b.f;
    return a.s > b.s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> w >> h;
    F0R(i, n){
        cin >> dan[i].f >> dan[i].s.f >> dan[i].s.s;
        int sm = dan[i].s.f-dan[i].s.s;
        dia[sm+MN].pb({{dan[i].f, dan[i].s.f}, i});
    }
    F0R(i, 2*MN){
        if(dia[i].empty()) continue;
        //cout << "tdif " << i-MN << "\n";
        sort(dia[i].begin(), dia[i].end(), comp);
        cur.clear();
        for(auto u : dia[i]){
            //cout << u.s << " ";
            if(u.f.f == 1) cur.pb({u.f.s, h});
            else cur.pb({w, u.f.s});
        }
        //cout << "\n";
        sort(cur.begin(), cur.end(), comp2);
        F0R(j, cur.size()){
            //cout << dia[i][j].f.f << " " << dia[i][j].f.s << " ";
            //cout << "end " << cur[j].f << " " << cur[j].s << "\n";
            ans[dia[i][j].s] = cur[j];
        }
    }
    F0R(i, n){
        cout << ans[i].f << " " << ans[i].s << "\n";
    }

    return 0;
}