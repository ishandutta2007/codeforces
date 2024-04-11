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

#define MN 200005
int t;
int n;
ll a[MN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> n;
        F0R(i, n){
            cin >> a[i];
        }
        sort(a, a+n);
        if(a[0] == a[n-1]) cout << n << "\n";
        else cout << "1\n";
    }

    return 0;
}