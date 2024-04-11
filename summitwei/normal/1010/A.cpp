#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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
#define MOD 998244353LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
int n; ld m; int a[MN], b[MN];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    ld cm = m;
    FOR(i, 1, n){
        cin >> a[i];
        if(a[i] == 1){
            cout << "-1\n";
            return 0;
        }
        cm = cm*a[i]/(a[i]-1);
    }
    FOR(i, 1, n){
        cin >> b[i];
        if(b[i] == 1){
            cout << "-1\n";
            return 0;
        }
        cm = cm*b[i]/(b[i]-1);
    }
    cout << fixed << setprecision(8) << cm-m << "\n";
    
    return 0;
}