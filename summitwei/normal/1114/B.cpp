#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n, m, k;
pii a[MN];
int good[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    F0R(i, n){
        cin >> a[i].f;
        a[i].s = i;
    }

    sort(a, a+n, greater<pii>() );

    ll sm = 0;
    F0R(i, m*k){
        sm += a[i].f;
        good[a[i].s] = true;
    }

    cout << sm << "\n";
    int cnt = 0;
    int amt = 0;
    F0R(i, n){
        if(good[i]) cnt++;
        if(cnt == m && amt != k-1){
            cout << i+1 << " ";
            cnt = 0;
            amt++;
        }
    }
    
    return 0;
}