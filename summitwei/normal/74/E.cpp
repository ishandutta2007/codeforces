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

#define MN 10
int gr[MN][MN];
vpii moves;

void swp(int x, int y, int d){ //0 = up/down, 1 = left/right
    if(d == 1){
        F0R(i, 6){
            moves.pb({'D', y});
            if(i % 2 == 0){
                moves.pb({'L', x});
            } else{
                moves.pb({'R', x});
            }
        }
        moves.pb({'D', y});
    } else{
        F0R(i, 6){
            moves.pb({'R', x});
            if(i % 2 == 0){
                moves.pb({'U', y});
            } else{
                moves.pb({'D', y});
            }
        }
        moves.pb({'R', x});
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    FOR(i, 1, 6){
        FOR(j, 1, 6){
            char c;
            cin >> c;
            if(c >= '0' && c <= '9'){
                gr[i][j] = c-'0';
            } else{
                gr[i][j] = 10+c-'A';
            }
        }
    }
    FOR(i, 1, 6){
        FOR(j, 1, 6){
            int v = 6*i+j-7;
            int ok = false;
            FOR(a, 1, 6){
                FOR(b, 1, 6){
                    if(gr[a][b] == v){
                        RFOR(c, b-1, j){
                            swp(a, c, 1);
                            swap(gr[a][c], gr[a][c+1]);
                        }
                        FOR(c, b, j-1){
                            swp(a, c, 1);
                            swap(gr[a][c], gr[a][c+1]);
                        }
                        RFOR(c, a-1, i){
                            swp(c, j, 0);
                            swap(gr[c][j], gr[c+1][j]);
                        }
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
            }
        }
    }
    cout << moves.size() << "\n";
    for(auto u : moves){
        cout << (char)u.f << u.s << "\n";
    }

    return 0;
}