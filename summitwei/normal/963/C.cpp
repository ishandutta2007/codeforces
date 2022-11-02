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
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n;
pair<pll, ll> ree[MN];
vector<pll> bruh[MN];
int t;
map<ll, int> hmph;

bool ok(ll a, ll b, ll c, ll d){
    return a/__gcd(a, b) == c/__gcd(c, d) && b/__gcd(a, b) == d/__gcd(c, d);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        cin >> ree[i].f.f >> ree[i].f.s >> ree[i].s;
        hmph[ree[i].f.f] = 0;
    }
    for(auto &u : hmph) u.s = t++;
    F0R(i, n){
        ree[i].f.f = hmph[ree[i].f.f];
        bruh[ree[i].f.f].pb({ree[i].f.s, ree[i].s});
    }
    F0R(i, t){
        sort(bruh[i].begin(), bruh[i].end());
        if(bruh[i].size() != bruh[0].size()){
            cout << "0\n";
            return 0;
        }
    }
    ll gcd = bruh[0][0].s;
    F0R(i, t){
        F0R(j, bruh[i].size()){
            if(bruh[0][j].f != bruh[i][j].f){
                cout << "0\n";
                return 0;
            }
            if(!ok(bruh[0][0].s, bruh[0][j].s, bruh[i][0].s, bruh[i][j].s)){
                cout << "0\n";
                return 0;
            }
            gcd = __gcd(gcd, bruh[i][j].s);
        }
    }

    int cnt = 0;
    //cout << gcd << "\n";
    for(ll i=1; i*i <= gcd; ++i){
        if(i*i == gcd) ++cnt;
        else if(gcd % i == 0) cnt += 2;
    }
    cout << cnt << "\n";

    return 0;
}