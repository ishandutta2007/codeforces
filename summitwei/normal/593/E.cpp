#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 25
int n, m;
int sz;
int q;

bool bl[MN];

ll prod[MN][MN]; //store temp products for mult
void matmult(ll a[][MN], ll b[][MN], ll dest[][MN]){
    memset(prod, 0, sizeof prod);
    FOR(i, 1, sz){
        FOR(j, 1, sz){
            FOR(k, 1, sz){
                prod[i][j] += a[i][k]*b[k][j];
                prod[i][j] %= MOD;
            }
        }
    }
 
    FOR(i, 1, sz){
        FOR(j, 1, sz){
            dest[i][j] = prod[i][j];
        }
    }
}

ll mat[MN][MN];
ll ans[MN][MN];
void matexp(ll ex){
    memset(ans, 0, sizeof ans);
    FOR(i, 1, sz){
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
ll cur[MN][MN];
ll wtmoo[MN][MN];

vi near[MN];
int conv(int x, int y){
    return x*m+y-m;
}
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> q;
    sz = n*m;
    int pt = 1;

    FOR(i, 1, sz) wtmoo[i][i] = 1;
    
    FOR(i, 1, n){
        FOR(j, 1, m){
            int loc = conv(i, j);
            F0R(dir, 5){
                int nx = i+dx[dir], ny = j+dy[dir];
                //cout << i << " " << j << " " << nx << " " << ny << "\n";
                if(nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
                int loc2 = conv(nx, ny);
                near[loc].pb(loc2);
                cur[loc][loc2] = 1;
                //cout << loc << " near " << loc2 << "\n";
            }
        }
    }
    /*FOR(i, 1, sz){
        FOR(j, 1, sz){
            cout << cur[i][j] << " ";
        }
        cout << "\n";
    }*/
    
    F0R(i, q){
        int ct, tp, x, y;
        cin >> tp >> x >> y >> ct;
        int loc = x*m+y-m;
        ll d = ct - pt;
        pt = ct;

        memcpy(mat, cur, sizeof mat);
        /*FOR(i, 1, sz){
            FOR(j, 1, sz){
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }*/
        matexp(d);

        /*FOR(i, 1, sz){
            FOR(j, 1, sz){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }*/

        matmult(wtmoo, ans, wtmoo);

        if(tp == 1){
            cout << wtmoo[1][loc] << "\n";
        } else if(tp == 2){
            bl[loc] = true;
            for(auto u : near[loc]){
                cur[u][loc] = 0;
                cur[loc][u] = 0;
            }
        } else if(tp == 3){
            bl[loc] = false;
            for(auto u : near[loc]){
                if(!bl[u]){
                    cur[u][loc] = 1;
                    cur[loc][u] = 1;
                }
            }
        }
        /*FOR(i, 1, sz){
            FOR(j, 1, sz){
                cout << wtmoo[i][j] << " ";
            }
            cout << "\n";
        }
        FOR(i, 1, sz){
            FOR(j, 1, sz){
                cout << cur[i][j] << " ";
            }
            cout << "\n";
        }*/
    }

    return 0;
}