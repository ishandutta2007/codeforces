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
#define MOD 1000000007
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
pll a[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    F0R(i, n){
        cin >> a[i].f >> a[i].s;
    }
    if(n % 2 == 1){
        cout << "NO\n";
        return 0;
    }
    pll mid = {(a[0].f+a[n/2].f), (a[0].s+a[n/2].s)};
    F0R(i, n/2){
        pll res = {(a[i].f+a[i+n/2].f), a[i].s+a[i+n/2].s};
        if(mid != res){
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}