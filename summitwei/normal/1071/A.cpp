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
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
ll a, b;
vi p, q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b;
    ll sm = a+b;
    ll tri = sqrt(sm);
    while(tri*(tri+1)/2 <= sm) ++tri;
    --tri;
    RFOR(i, tri, 1){
        if(a >= i){
            p.pb(i);
            a -= i;
        } else{
            q.pb(i);
        }
    }
    cout << p.size() << "\n";
    for(auto u : p) cout << u << " ";
    cout << "\n";
    cout << q.size() << "\n";
    for(auto u : q) cout << u << " ";
    cout << "\n";
    return 0;
}