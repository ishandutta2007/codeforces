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

#define MN 200005
int n, q;
int a[MN];
int ls[MN];
int lt[MN];

int nd[MN];
int dfs(int cn, int st, int c){
    if(nd[cn] != 0) return 0;
    nd[cn] = c;
    int ans = cn;
    ans = max(ans, dfs(lt[cn], st, c));
    if(cn != st) ans = max(ans, dfs(cn-1, st, c));
    
    return ans;
}

int cc(int l, int r){
    map<int, int> hmm;
    FOR(i, l, r){
        hmm[a[i]]++;
    }
    int mx = 0;
    for(auto u : hmm){
        mx = max(mx, u.s);
    }
    return mx;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    F0R(i, n){
        cin >> a[i];
        ls[a[i]] = i;
    }
    F0R(i, n){
        lt[i] = ls[a[i]];
    }
    int sm = 0;
    int co = 0;
    F0R(i, n){
        if(nd[i] == 0){
            int v = dfs(i, i, ++co);
            sm += cc(i, v);
        }
    }
    cout << n-sm << "\n";
    
    return 0;
}