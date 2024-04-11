#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 55
int n;
int gr[MN][MN];
void dfs(int x, int y){
    if(x <= n-2 && gr[x+2][y] == -1){
        cout << "? " << x << " " << y << " " << x+2 << " " << y << "\n";
        cout.flush();
        int resp;
        cin >> resp;
        if(resp == -1) exit(0);
        if(resp == 0) gr[x+2][y] = !gr[x][y];
        else gr[x+2][y] = gr[x][y];
        dfs(x+2, y);
    }
    if(y <= n-2 && gr[x][y+2] == -1){
        cout << "? " << x << " " << y << " " << x << " " << y+2 << "\n";
        cout.flush();
        int resp;
        cin >> resp;
        if(resp == -1) exit(0);
        if(resp == 0) gr[x][y+2] = !gr[x][y];
        else gr[x][y+2] = gr[x][y];
        dfs(x, y+2);
    }
    if(x <= n-1 && y <= n-1 && gr[x+1][y+1] == -1){
        cout << "? " << x << " " << y << " " << x+1 << " " << y+1 << "\n";
        cout.flush();
        int resp;
        cin >> resp;
        if(resp == -1) exit(0);
        if(resp == 0) gr[x+1][y+1] = !gr[x][y];
        else gr[x+1][y+1] = gr[x][y];
        dfs(x+1, y+1);
    }
}
int gr2[MN][MN];
void dfs2(int x, int y){
    //cout << "doing " << x << " " << y << "\n";
    if(x <= n-2 && gr2[x+2][y] == -1){
        cout << "? " << x << " " << y << " " << x+2 << " " << y << "\n";
        cout.flush();
        int resp;
        cin >> resp;
        if(resp == -1) exit(0);
        if(resp == 0) gr2[x+2][y] = !gr2[x][y];
        else gr2[x+2][y] = gr2[x][y];
        dfs2(x+2, y);
    }
    if(y <= n-2 && gr2[x][y+2] == -1){
        cout << "? " << x << " " << y << " " << x << " " << y+2 << "\n";
        cout.flush();
        int resp;
        cin >> resp;
        if(resp == -1) exit(0);
        if(resp == 0) gr2[x][y+2] = !gr2[x][y];
        else gr2[x][y+2] = gr2[x][y];
        dfs2(x, y+2);
    }
    if(x <= n-1 && y <= n-1 && gr2[x+1][y+1] == -1){
        cout << "? " << x << " " << y << " " << x+1 << " " << y+1 << "\n";
        cout.flush();
        int resp;
        cin >> resp;
        if(resp == -1) exit(0);
        if(resp == 0) gr2[x+1][y+1] = !gr2[x][y];
        else gr2[x+1][y+1] = gr2[x][y];
        dfs2(x+1, y+1);
    }
    if(x >= 2 && y >= 2 && gr2[x-1][y-1] == -1){
        cout << "? " << x-1 << " " << y-1 << " " << x << " " << y << "\n";
        cout.flush();
        int resp;
        cin >> resp;
        if(resp == -1) exit(0);
        if(resp == 0) gr2[x-1][y-1] = !gr2[x][y];
        else gr2[x-1][y-1] = gr2[x][y];
        dfs2(x-1, y-1);
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    cin >> n;
    memset(gr, -1, sizeof gr);
    gr[1][1] = 1;
    gr[n][n] = 0;
    memset(gr2, -1, sizeof gr2);
    gr2[1][2] = 0;

    dfs(1, 1);
    dfs2(1, 2);
    /*FOR(i, 1, n){
        FOR(j, 1, n){
            cout << gr[i][j] << " ";
        }
        cout << "\n";
    }
    FOR(i, 1, n){
        FOR(j, 1, n){
            cout << gr2[i][j] << " ";
        }
        cout << "\n";
    }*/
    int sm = -1;
    FOR(i, 1, n-3){
        if(gr[1][i] == -1){
            if((gr2[1][i] == gr2[1][i+2]) == (gr[1][i+1]==gr[1][i+3])){
                cout << "? 1 " << i << " 1 " << i+3 << "\n";
                cout.flush();
                int resp;
                cin >> resp;
                if(resp == -1) exit(0);
                if(resp == 1){
                    sm = (gr2[1][i] == gr[1][i+3]);
                } else{
                    sm = !(gr2[1][i] == gr[1][i+3]);
                }
                break;
            }
        } else{
            if((gr[1][i] == gr[1][i+2]) == (gr2[1][i+1]==gr2[1][i+3])){
                cout << "? 1 " << i << " 1 " << i+3 << "\n";
                cout.flush();
                int resp;
                cin >> resp;
                if(resp == -1) exit(0);
                if(resp == 1){
                    sm = (gr[1][i] == gr2[1][i+3]);
                } else{
                    sm = !(gr[1][i] == gr2[1][i+3]);
                }
                break;
            }
        }
    }
    if(sm == -1){
        FOR(i, 1, n-3){
            if(gr[i][n] == -1){
                if((gr2[i][n] == gr2[i+2][n]) == (gr[i+1][n]==gr[i+3][n])){
                    cout << "? " << i << " " << n << " " << i+3 << " " << n << "\n";
                    cout.flush();
                    int resp;
                    cin >> resp;
                    if(resp == -1) exit(0);
                    if(resp == 1){
                        sm = (gr2[i][n] == gr[i+3][n]);
                    } else{
                        sm = !(gr2[i][n] == gr[i+3][n]);
                    }
                    break;
                }
            } else{
                if((gr[i][n] == gr[i+2][n]) == (gr2[i+1][n]==gr2[i+3][n])){
                    cout << "? " << i << " " << n << " " << i+3 << " " << n << "\n";
                    cout.flush();
                    int resp;
                    cin >> resp;
                    if(resp == -1) exit(0);
                    if(resp == 1){
                        sm = (gr[i][n] == gr2[i+3][n]);
                    } else{
                        sm = !(gr[i][n] == gr2[i+3][n]);
                    }
                    break;
                }
            }
        }
    }
    if(sm == -1){
        if(gr[1][n-2] != -1){
            if((gr[1][n-2] == gr[1][n]) == (gr2[1][n-1] == gr2[2][n])){
                cout << "? 1 " << n-2 << " 2 " << n << "\n";
                cout.flush();
                int resp;
                cin >> resp;
                if(resp == -1) exit(0);
                if(resp == 1){
                    sm = (gr[1][n-2] == gr2[2][n]);
                } else{
                    sm = !(gr[1][n-2] == gr2[2][n]);
                }
            } else{
                cout << "? 1 " << n-1 << " 3 " << n << "\n";
                cout.flush();
                int resp;
                cin >> resp;
                if(resp == -1) exit(0);
                if(resp == 1){
                    sm = (gr[1][n-1] == gr2[3][n]);
                } else{
                    sm = !(gr[1][n-1] == gr2[3][n]);
                }
            }
        } else{
            if((gr2[1][n-2] == gr2[1][n]) == (gr[1][n-1] == gr[2][n])){
                cout << "? 1 " << n-2 << " 2 " << n << "\n";
                cout.flush();
                int resp;
                cin >> resp;
                if(resp == -1) exit(0);
                if(resp == 1){
                    sm = (gr2[1][n-2] == gr[2][n]);
                } else{
                    sm = !(gr2[1][n-2] == gr[2][n]);
                }
            } else{
                cout << "? 1 " << n-1 << " 3 " << n << "\n";
                cout.flush();
                int resp;
                cin >> resp;
                if(resp == -1) exit(0);
                if(resp == 1){
                    sm = (gr2[1][n-1] == gr[3][n]);
                } else{
                    sm = !(gr2[1][n-1] == gr[3][n]);
                }
            }
        }
    }
    cout << "!\n";
    //cout << sm << "\n";
    FOR(i, 1, n){
        FOR(j, 1, n){
            if(gr[i][j] != -1){
                cout << gr[i][j];
            } else{
                cout << (gr2[i][j] == sm);
            }
        }
        cout << "\n";
    }

    return 0;
}