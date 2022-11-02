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

#define MN 300005
int n, k;
int c[MN];
int tim[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    FOR(i, 1, n){
        cin >> c[i];
    }

    priority_queue<pii> ree;
    FOR(i, 1, k){
        ree.push({c[i], i});
    }
    ll sm = 0;
    FOR(i, k+1, k+n){
        if(i <= n) ree.push({c[i], i});
        pii top = ree.top();
        ree.pop();
        tim[top.s] = i;
        sm = sm+1LL*top.f*(i-top.s);
    }

    cout << sm << "\n";
    FOR(i, 1, n) cout << tim[i] << " ";
    cout << "\n";

    return 0;
}