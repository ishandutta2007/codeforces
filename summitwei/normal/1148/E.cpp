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
int n;
pii s[MN];
int t[MN];
int d[MN];

vector<pair<pii, int> > mvs;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        cin >> s[i].f;
        s[i].s = i;
    }
    F0R(i, n){
        cin >> t[i];
    }

    sort(s, s+n);
    sort(t, t+n);
    ll sm = 0;
    F0R(i, n){
        d[i] = t[i]-s[i].f;
        sm = sm+d[i];
        if(sm < 0){
            cout << "NO\n";
            return 0;
        }
    }
    if(sm != 0){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    int l = 0, r = 1;
    while(l < n){
        while(l != n && d[l] == 0) l++;
        while(r != n && d[r] >= 0) r++;
        if(l == n) break;
        
        int amt = min(d[l], -d[r]);
        mvs.pb(mp(mp(s[l].s, s[r].s), amt));
        d[l] -= amt;
        d[r] += amt;
    }

    cout << mvs.size() << "\n";
    for(auto u : mvs){
        cout << u.f.f+1 << " " << u.f.s+1 << " " << u.s << "\n";
    }

    return 0;
}