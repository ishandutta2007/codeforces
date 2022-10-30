#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
int n; ll h;
ll a[MN];

bool ree(pll a, pll b){
    return a.s < b.s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> h;
    FOR(i, 1, n){
        cin >> a[i];
    }

    FOR(i, 1, n){
        sort(a+1, a+i+1);

        ll sm = 0;
        for(int j=i; j>=1; j-=2){
            sm += a[j];
        }
        //if(i % 2 == 0) sm += a[1];
        //cout << sm << "\n";

        if(sm > h){
            cout << i-1 << "\n";
            return 0;
        }
    }
    cout << n << "\n";

    return 0;
}