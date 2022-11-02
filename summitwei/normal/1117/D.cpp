#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 105
ll n, m;
ll mat[MN][MN];

ll prod[MN][MN]; //store temp products for mult
ll ans[MN][MN];
void matmult(ll a[][MN], ll b[][MN], ll dest[][MN]){
    memset(prod, 0, sizeof prod);
    F0R(i, m){
        F0R(j, m){
            F0R(k, m){
                prod[i][j] += a[i][k]*b[k][j];
                prod[i][j] %= MOD;
            }
        }
    }

    F0R(i, m){
        F0R(j, m){
            dest[i][j] = prod[i][j];
        }
    }
}

void matexp(ll ex){
    F0R(i, m){
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    F0R(i, m-1){
        mat[i][i+1] = 1;
    }
    mat[m-1][0] = 1;
    mat[m-1][m-1] = 1;

    matexp(n);

    /*F0R(i, m){
        F0R(j, m){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }*/

    cout << ans[m-1][m-1] << "\n";

    return 0;
}