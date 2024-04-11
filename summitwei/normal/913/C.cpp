#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
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

#define MN 35
int n;
ll l;
ll a[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l;
    F0R(i, n) cin >> a[i];
    FOR(i, 1, n-1){
        if(a[i] > a[i-1]*2) a[i] = a[i-1]*2;
    }
    FOR(i, n, 30) a[i] = a[i-1]*2;
    n = 31;
    /*F0R(i, n){
        cout << a[i] << " ";
    }
    cout << "\n";*/

    ll res = 1LL<<62;
    ll cur = 0;
    RFOR(i, n-1, 0){
        if(!((1<<i)&l)){
            //cout << "trying " << i << " " << cur+a[i] << "\n";
            res = min(res, cur+a[i]);
        } else{
            cur += a[i];
        }
    }
    //cout << "fin " << cur << "\n";
    res = min(res, cur);
    cout << res << "\n";
    
    return 0;
}