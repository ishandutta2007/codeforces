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

#define MN 55
int n, m;
char st[2][MN][MN];
bool swp;
vpii p[2];

void res(int r, int c, bool dir, int v){ //false = want to go right
    //cout << "resolving " << r << " " << c << " " << dir << " " << v << "\n";
    if(!dir){
        if(st[v][r][c] == 'L') return;

        res(r, c+1, true, v);

        p[v].pb({r, c});
        st[v][r][c] = st[v][r+1][c] = 'L';
        st[v][r][c+1] = st[v][r+1][c+1] = 'R';
    } else{
        if(st[v][r][c] == 'U') return;
        
        res(r+1, c, false, v);

        p[v].pb({r, c});
        st[v][r][c] = st[v][r][c+1] = 'U';
        st[v][r+1][c] = st[v][r+1][c+1] = 'D';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    if(m % 2){
        swp = true;
    }
    F0R(i, n){
        F0R(j, m){
            char c;
            cin >> c;
            if(swp){
                if(c == 'U') c = 'L';
                else if(c == 'L') c = 'U';
                else if(c == 'D') c = 'R';
                else c = 'D';
                st[0][j][i] = c;
            } else{
                st[0][i][j] = c;
            }
        }
    }
    F0R(i, n){
        F0R(j, m){
            char c;
            cin >> c;
            if(swp){
                if(c == 'U') c = 'L';
                else if(c == 'L') c = 'U';
                else if(c == 'D') c = 'R';
                else c = 'D';
                st[1][j][i] = c;
            } else{
                st[1][i][j] = c;
            }
        }
    }
    if(swp) swap(n, m);
    /*F0R(i, n){
        F0R(j, m){
            cout << st[0][i][j];
        }
        cout << "\n";
    }*/
    F0R(i, n){
        for(int j=0; j<m; j+=2){
            res(i, j, false, 0);
            res(i, j, false, 1);
        }
    }

    cout << p[0].size()+p[1].size() << "\n";
    F0R(i, p[0].size()){
        if(swp){
            cout << p[0][i].s+1 << " " << p[0][i].f+1 << "\n";
        } else{
            cout << p[0][i].f+1 << " " << p[0][i].s+1 << "\n";
        }
    }
    RFOR(i, p[1].size()-1, 0){
        if(swp){
            cout << p[1][i].s+1 << " " << p[1][i].f+1 << "\n";
        } else{
            cout << p[1][i].f+1 << " " << p[1][i].s+1 << "\n";
        }
    }

    return 0;
}