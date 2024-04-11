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

#define MN 405
int k, n;
int a[MN];
int ps[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tot = 0;

    cin >> n >> k;
    F0R(i, n){
        cin >> a[i];
        tot += a[i];

        ps[i%k] += a[i];
    }

    /*F0R(i, k){
        cout << ps[i] << " ";
    }*/

    int mx = -INF;
    int mn = INF;
    F0R(i, k){
        mx = max(mx, ps[i]);
        mn = min(mn, ps[i]);
    }

    cout << max(abs(tot-mx), abs(tot-mn));

    return 0;
}