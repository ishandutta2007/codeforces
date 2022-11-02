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
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 105
int n, m;
vpii e[MN];
int dp[MN][MN][26];

bool res(int x, int y, int c){
    if(dp[x][y][c] != -1) return dp[x][y][c];
    for(auto u : e[x]){
        if(u.s < c) continue;
        if(!res(y, u.f, u.s)){
            dp[x][y][c] = 1;
            return true;
        }
    }
    dp[x][y][c] = 0;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof dp);

    cin >> n >> m;
    F0R(_, m){
        int a, b; char c;
        cin >> a >> b >> c;
        e[a].pb({b, c-'a'});
        //e[b].pb({a, c-'a'});
    }
    FOR(i, 1, n){
        FOR(j, 1, n){
            if(res(i, j, 0)){
                cout << "A";
            } else{
                cout << "B";
            }
        }
        cout << "\n";
    }
    
    return 0;
}