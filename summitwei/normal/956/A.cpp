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

#define MN 55
int n, m;
char gr[MN][MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 1, n){
        FOR(j, 1, m){
            cin >> gr[i][j];
        }
    }

    FOR(i, 1, n){
        FOR(j, i+1, n){
            bool sm = true;
            bool inte = false;
            FOR(k, 1, m){
                if(gr[i][k] == '#'){
                    if(gr[j][k] == '#'){
                        inte = true;
                    } else{
                        sm = false;
                    }
                } else{
                    if(gr[j][k] == '#'){
                        sm = false;
                    }
                }
            }
            if(!sm && inte){
                cout << "No\n";
                return 0;
            }
        }
    }
    FOR(i, 1, m){
        FOR(j, i+1, m){
            bool sm = true;
            bool inte = false;
            FOR(k, 1, n){
                if(gr[k][i] == '#'){
                    if(gr[k][j] == '#'){
                        inte = true;
                    } else{
                        sm = false;
                    }
                } else{
                    if(gr[k][j] == '#'){
                        sm = false;
                    }
                }
            }
            if(!sm && inte){
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
    return 0;
}