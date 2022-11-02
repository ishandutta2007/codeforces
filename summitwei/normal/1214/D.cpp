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

#define MN 1000005
int n, m;
vector<bool> aah[MN];
vector<bool> ds[MN];
vector<bool> ds2[MN];
int tims[MN*2];

void dfs1(int x, int y){
    //cout << x << " " << y << "\n";
    if(x >= n || y >= m) return;
    if(ds[x][y]) return;
    //cout << "wtmoo\n";
    if(aah[x][y]) return;
    //cout << "wtmoo\n";
    //cout << "wtmoo\n";
    ds[x][y] = true;
    dfs1(x+1, y);
    dfs1(x, y+1);
}
void dfs2(int x, int y){
    if(x < 0 || y < 0) return;
    if(ds2[x][y]) return;
    if(aah[x][y]) return;
    ds2[x][y] = true;
    dfs2(x-1, y);
    dfs2(x, y-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    F0R(i, n){
        aah[i].resize(m);
        ds[i].resize(m);
        ds2[i].resize(m);
    }
    F0R(i, n){
        F0R(j, m){
            char c;
            cin >> c;
            aah[i][j] = (c=='#');
        }
    }
    dfs1(0, 0);
    dfs2(n-1, m-1);

    if(!ds[n-1][m-1]){
        cout << "0\n";
        return 0;
    }

    F0R(i, n){
        F0R(j, m){
            if(ds[i][j] && ds2[i][j]) ++tims[i+j];
        }
    }

    FOR(i, 1, n+m-3){
        if(tims[i] == 1){
            cout << "1\n";
            return 0;
        }
    }

    cout << "2\n";
    return 0;
}