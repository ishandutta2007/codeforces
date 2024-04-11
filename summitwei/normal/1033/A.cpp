#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 1005

#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)

/*bool vis[MAX_N][MAX_N];
int n, ax, ay;

void dfs(int x, int y){
    if(vis[x][y]) return;
    vis[x][y] = true;

    int blah[3];

    FOR(i, -1, 2){
        FOR(j, -1, 2){
            int newX = x+i;
            int newY = y+j;
            if(vis[newX][newY]) continue;

        }
    }    
}*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ax, ay;
    int bx, by, cx, cy;

    cin >> n >> ax >> ay;
    cin >> bx >> by >> cx >> cy;

    if((cx-ax)*(bx-ax) > 0 && (cy-ay)*(by-ay) > 0){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }

    return 0;
}