#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
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
int n, m;
bool gr[MN][MN];
int fsx[MN], lsx[MN], fsy[MN], lsy[MN];
bool vis[MN][MN];

void dfs(int x, int y){
    if(x<0 || y<0) return;
    //cout << "doing " << x << " " << y << "\n";
    if(vis[x][y]) return;
    vis[x][y] = true;
    if(fsx[x] < y) dfs(x, y-1);
    if(lsx[x] > y) dfs(x, y+1);
    if(fsy[y] < x) dfs(x-1, y);
    if(lsy[y] > x) dfs(x+1, y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    F0R(i, n){
        F0R(j, m){
            char c;
            cin >> c;
            if(c == '#') gr[i][j] = 1;
        }
    }
    F0R(i, n) fsx[i] = lsx[i] = -1;
    F0R(i, m) fsy[i] = lsy[i] = -1;
    F0R(i, n){
        F0R(j, m){
            if(gr[i][j] == 1){
                fsx[i] = fsx[i]==-1?j:min(fsx[i], j);
                lsx[i] = max(lsx[i], j);
                fsy[j] = fsy[j]==-1?i:min(fsy[j], i);
                lsy[j] = max(lsy[j], i);
            }
        }
    }
    //F0R(i, n) cout << fsx[i] << " " << lsx[i] << "\n";
    //F0R(i, m) cout << fsy[i] << " " << lsy[i] << "\n";
    bool alx = false;
    F0R(i, n){
        if(fsx[i] == -1) alx = true;
    }
    bool aly = false;
    F0R(i, m){
        if(fsy[i] == -1) aly = true;
    }
    if(alx != aly){
        cout << "-1\n";
        return 0;
    }
    int cnt = 0;
    F0R(i, n){
        F0R(j, m){
            if(gr[i][j] && !vis[i][j]){
                ++cnt;
                dfs(i, j);
            }
        }
    }
    F0R(i, n){
        F0R(j, m){
            if(!gr[i][j] && vis[i][j]){
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << cnt << "\n";
    
    return 0;
}