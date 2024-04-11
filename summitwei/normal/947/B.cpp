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
#define MOD 998244353LL //119*2^23+1
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
ll v[MN];
ll t[MN];
ll pst[MN];
ll ful[MN];
ll res[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> v[i];
    }
    FOR(i, 1, n){
        cin >> t[i];
        pst[i] = pst[i-1]+t[i];
    }
    FOR(i, 1, n){
        int loc = upper_bound(pst, pst+n+1, v[i]+pst[i-1])-pst;
        ful[i]++;
        ful[loc]--;
        res[loc] += v[i]-(pst[loc-1]-pst[i-1]);
    }
    int cur = 0;
    FOR(i, 1, n){
        cur += ful[i];
        res[i] = res[i]+cur*t[i];
        cout << res[i] << " ";
    }
    

    return 0;
}