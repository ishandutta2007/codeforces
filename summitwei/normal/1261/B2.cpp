#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef vector<int> vi;
typedef vector<long long> vll;
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

#define MN 200005
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
int n;
pii a[MN];
int m;
pair<pii, int> req[MN];
int ans[MN];
int orig[MN];

ordered_set os;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> a[i].f;
        a[i].s = -i;
        orig[i] = a[i].f;
    }
    sort(a+1, a+n+1, greater<pii>());
    cin >> m;
    F0R(i, m){
        cin >> req[i].f.f >> req[i].f.s;
        req[i].s = i;
    }
    sort(req, req+m);
    int cur = 0;
    FOR(i, 1, n){
        os.insert(-a[i].s);
        while(req[cur].f.f == i){
            ans[req[cur].s] = *os.find_by_order(req[cur].f.s-1);
            ++cur;
        }
    }

    F0R(i, m){
        cout << orig[ans[i]] << "\n";
    }
    
    return 0;
}