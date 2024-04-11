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

#define MN 3005
int n, k1, k2;
ll a[MN];
ll b[MN];
ll d[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k1 >> k2;
    F0R(i, n){
        cin >> a[i];
    }
    F0R(i, n){
        cin >> b[i];
        d[i] = abs(a[i]-b[i]);
    }
    F0R(_, k1+k2){
        int mx = 0;
        F0R(i, n){
            if(d[i] > d[mx]) mx = i;
        }
        if(d[mx] == 0) d[mx] = 1;
        else d[mx]--;
    }
    ll sm = 0;
    F0R(i, n){
        sm += d[i]*d[i];
    }

    cout << sm << "\n";

    return 0;
}