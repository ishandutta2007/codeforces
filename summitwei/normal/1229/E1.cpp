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
#define MOD 1000000007LL
#define INV 570000004LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 22
int n;
ll p[MN][MN];
vi permsA[MN];
vi permsB[MN];
ll bmA[1<<MN];
ll bmB[1<<MN];
ll f[1<<MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 0;
    int aah[6] = {0, 1, 2, 3, 4, 5};
    do{
        if(aah[0] < aah[1] && aah[1] < aah[2] && aah[3] < aah[4] && aah[4] < aah[5]){
            permsA[t] = {aah[0], aah[1], aah[2]};
            permsB[t] = {aah[3], aah[4], aah[5]};
            ++t;
        }
    } while(next_permutation(aah, aah+6));

    cin >> n;
    F0R(i, n){
        F0R(j, n){
            cin >> p[i][j];
            p[i][j] = (p[i][j]*INV)%MOD;
        }
    }
    F0R(i, 6){
        FOR(j, n, 6-1){
            if(i == j) p[i][j] = 1;
            else{p[i][j] = 0; p[j][i] = 0;}
        }
    }
    n = 6;
    /*F0R(i, n){
        F0R(j, n){
            cout << p[i][j] << " ";
        }
        cout << "\n";
    }*/
    F0R(i, 1<<18){
        ll prob1 = 1;
        ll prob2 = 1;
        int bm1 = 0;
        int bm2 = 0;
        F0R(j, 6){
            F0R(k, 3){
                int res = j*3+k;
                if((1<<res) & i){
                    prob1 *= p[j][k];
                    prob2 *= p[j][k+3];
                } else{
                    prob1 *= (1+MOD-p[j][k]);
                    prob2 *= (1+MOD-p[j][k+3]);
                }
                prob1 %= MOD;
                prob2 %= MOD;
            }
        }
        F0R(ot, 20){
            int ord[3] = {0, 1, 2};
            bool ok = false;
            do{
                bool ok2 = true;
                F0R(j, 3){
                    int val = permsA[ot][ord[j]];
                    int loc = val*3+j;
                    if(!((1<<loc)&i)){
                        ok2 = false;
                        break;
                    }
                }
                if(ok2){
                    ok = true;
                    break;
                }
            } while(next_permutation(ord, ord+3));
            if(ok){
                bm1 ^= (1<<ot);
            }
        }
        F0R(ot, 20){
            int ord[3] = {0, 1, 2};
            bool ok = false;
            do{
                bool ok2 = true;
                F0R(j, 3){
                    int val = permsB[ot][ord[j]];
                    int loc = val*3+j;
                    if(!((1<<loc)&i)){
                        ok2 = false;
                        break;
                    }
                }
                if(ok2){
                    ok = true;
                    break;
                }
            } while(next_permutation(ord, ord+3));
            if(ok){
                bm2 ^= (1<<ot);
            }
        }
        /*if(prob1 != 0){
            cout << i << " 1 " << bm1 << " and " << prob1 << "\n";
        }
        if(prob2 != 0){
            cout << i << " 2 " << bm2 << " and " << prob2 << "\n";
        }*/
        bmA[bm1] = (bmA[bm1]+prob1)%MOD;
        bmB[bm2] = (bmB[bm2]+prob2)%MOD;
    }
    F0R(i, (1<<20)){
        f[i] = bmA[i];
        /*if(f[i] != 0){
            cout << i << " " << f[i] << "\n";
        }*/
    }
    F0R(i, 20){
        F0R(mask, (1<<20)){
            if(mask & (1<<i)){
                f[mask] += f[mask ^ (1<<i)];
                f[mask] %= MOD;
            }
        }
    }
    ll sm = 0;
    F0R(i, (1<<20)){
        int o = (1<<20)-1;
        /*if(bmA[i] != 0){
            cout << i << " " << bmA[i] << " " << f[i] << "\n";
        }*/
        sm += (bmB[i]*f[o^i]);
        sm %= MOD;
    }
    cout << (1+MOD-sm)%MOD << "\n";

    return 0;
}