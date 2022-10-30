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
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 200005
int n, m, k;
vi e[MN];
int a[MN];
int d[MN][2];
 
queue<int> ree;
void bfs(int st, int tp){
    while(!ree.empty()){
        ree.pop();
    }
    ree.push(st);
    d[st][tp] = 0;
    while(!ree.empty()){
        int cn = ree.front();
        ree.pop();
        for(auto nn : e[cn]) if(d[nn][tp] == -1){
            d[nn][tp] = d[cn][tp]+1;
            ree.push(nn);
        }
    }
}
 
bool comp(int x, int y){
    int dx = d[x][0]-d[x][1], dy = d[y][0]-d[y][1];
    if(dx != dy) return dx < dy;
    return x < y;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    memset(d, -1, sizeof d);
 
    cin >> n >> m >> k;
    F0R(i, k){
        cin >> a[i];
    }
    F0R(_, m){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
 
    bfs(1, 0);
    bfs(n, 1);
    /*FOR(i, 1, n){
        cout << d[i][0] << " " << d[i][1] << "\n";
    }
    cout << "\n";*/
 
    sort(a, a+k, comp);
    /*F0R(i, k){
        cout << a[i] << " ";
    }
    cout << "\n";*/
    int ans = -INF;
    int bst = -INF;
    F0R(i, k){
        ans = max(ans, bst+d[a[i]][1]);
        bst = max(bst, d[a[i]][0]);
    }
    if(ans < 0) ans = INF;
    cout << min(d[n][0], ans+1) << "\n";
 
    return 0;
}