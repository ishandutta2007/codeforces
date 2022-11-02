#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
int t;
int n;
int a[MN];
int mn[MN];
int mx[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> n;
        FOR(i, 1, n){
            cin >> a[i];
        }
        mn[0] = INF; mx[n+1] = 0;
        FOR(i, 1, n){
            mn[i] = min(mn[i-1], a[i]);
        }
        RFOR(i, n, 1){
            mx[i] = max(mx[i+1], a[i]);
        }
        bool ok = true;
        FOR(i, 2, n){
            if(a[i] < a[1] && a[i] > mx[i+1]) ok = false;
        }
        if(ok){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
        FOR(i, 1, n){
            mn[i] = mx[i] = 0;
        }
    }
    
    return 0;
}