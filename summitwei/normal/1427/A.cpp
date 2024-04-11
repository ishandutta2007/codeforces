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
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 55 //check limits you incompetent ree
int n;
int a[MN];
int ps[MN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    F0R(_, t){
        cin >> n;
        int sm = 0;
        FOR(i, 1, n){
            cin >> a[i];
            sm += a[i];
        }
        sort(a+1, a+n+1);
        if(sm==0){
            cout << "NO\n";
        } else if(sm<0){
            cout << "YES\n";
            FOR(i, 1, n) cout << a[i] << " ";
            cout << "\n";
        } else{
            cout << "YES\n";
            RFOR(i, n, 1) cout << a[i] << " ";
            cout << "\n";
        }
    }

    return 0;
}