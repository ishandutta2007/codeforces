#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
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
int n;
ll a[MN][MN];
ll v[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        F0R(j, n){
            cin >> a[i][j];
        }
    }
    v[0] = sqrt(a[0][1]*a[0][2]/a[1][2]);
    FOR(i, 1, n-1){
        v[i] = a[0][i]/v[0];
    }
    F0R(i, n){
        cout << v[i] << " ";
    }

    return 0;
}