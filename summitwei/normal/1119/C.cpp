#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
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

#define MN 505
int n, m;
int a[MN][MN];
int b[MN][MN];
int r[MN][2];
int c[MN][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    F0R(i, n){
        F0R(j, m){
            cin >> a[i][j];
            if(a[i][j]){
                r[i][0]++;
                c[j][0]++;
            }
        }
    }
    F0R(i, n){
        F0R(j, m){
            cin >> b[i][j];
            if(b[i][j]){
                r[i][1]++;
                c[j][1]++;
            }
        }
    }
    
    F0R(i, n){
        if((r[i][0]-r[i][1])%2){
            cout << "No\n";
            return 0;
        }
    }
    F0R(j, m){
        if((c[j][0]-c[j][1])%2){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}