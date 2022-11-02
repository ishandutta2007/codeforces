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

#define MN 2005
int n;
int rt;
int p[MN];
vi ch[MN];
vi a[MN];
int c[MN];
int inv[MN];

bool dfs(int cn){
    for(auto nn : ch[cn]){
        if(!dfs(nn)) return false;
        for(auto u : a[nn]) a[cn].pb(u);
    }
    if(c[cn] > a[cn].size()) return false;
    a[cn].insert(a[cn].begin()+c[cn], cn);

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> p[i] >> c[i];
        if(p[i] == 0) rt = i;
        else{
            ch[p[i]].pb(i);
        }
    }

    if(!dfs(rt)){
        cout << "NO\n";
    } else{
        cout << "YES\n";
        F0R(i, n){
            inv[a[rt][i]] = i;
        }
        FOR(i, 1, n){
            cout << inv[i]+1 << " ";
        }
        cout << "\n";
    }

    return 0;
}