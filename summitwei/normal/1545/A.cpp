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
typedef unsigned long long ull;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.000000000001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n;
int a[MN], b[MN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    F0R(_, t){
        cin >> n;
        F0R(i, n){
            if(i%2==0) cin >> a[i/2];
            else cin >> b[i/2];
        }
        sort(a, a+(n+1)/2);
        sort(b, b+n/2);
        bool ok = true;
        F0R(i, n-1){
            if(i%2==0){
                if(a[i/2] > b[i/2]) ok = false;
            } else{
                if(b[i/2] > a[(i+1)/2]) ok = false;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}