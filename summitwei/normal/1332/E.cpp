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
ll n, m, l, r;
ll mat[2][2];

ll prod[2][2]; //store temp products for mult
ll ans[2][2];
void matmult(ll a[][2], ll b[][2], ll dest[][2]){
    memset(prod, 0, sizeof prod);
    F0R(i, 2){
        F0R(j, 2){
            F0R(k, 2){
                prod[i][j] += a[i][k]*b[k][j];
                prod[i][j] %= MOD;
            }
        }
    }
 
    F0R(i, 2){
        F0R(j, 2){
            dest[i][j] = prod[i][j];
        }
    }
}

void matexp(ll ex){
    F0R(i, 2){
        ans[i][i] = 1;
    }
 
    while(ex > 0){
        if(ex % 2 == 0){
            matmult(mat, mat, mat);
            ex /= 2;
        } else{
            matmult(ans, mat, ans);
            ex--;
        }
    }
}

ll modExp(ll b, ll ex){
    ll prod = 1;
    while(ex > 0){
        if(ex % 2 == 0){
            b = (b * b) % MOD;
            ex /= 2;
        } else{
            prod = (prod*b) % MOD;
            ex--;
        }
    }
    
    return prod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> l >> r;
    if((n*m)%2){
        cout << modExp(r-l+1, (n*m));
        return 0;
    }
    ll o = (r+1)/2-(l)/2, e=(r/2)-(l-1)/2;
    mat[0][0] = mat[1][1] = e%MOD; mat[0][1] = mat[1][0] = o%MOD;

    //cout << o << " " << e << "\n";

    matexp(n*m);
    cout << ans[0][0] << "\n";
    
    return 0;
}