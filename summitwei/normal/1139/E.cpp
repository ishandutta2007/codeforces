#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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

#define MN 5005
int n, m, d;
int pot[MN];
int clb[MN];
pii days[MN]; //(club, pow)
bool used[MN];

vi e[MN];
int mat[MN];
bool vis[MN]; //reset vis!

bool aug(int cn){
    if(vis[cn]) return false;
    vis[cn] = 1;
    
    F0R(i, e[cn].size()){
        int nn = e[cn][i];
        if(mat[nn] == -1 || aug(mat[nn])){
            mat[nn] = cn; //idt anything else needs to be worried abt? it should just work
            return true;
        }
    }
    return false;
}
bool chk(int cur){
    memset(vis, 0, sizeof vis);
    
    //cout << "checking " << cur << "\n";
    return aug(cur);
}

int ans[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    memset(mat, -1, sizeof mat);

    cin >> n >> m;
    FOR(i, 1, n){
        cin >> pot[i];
    }
    FOR(i, 1, n){
        cin >> clb[i];
    }
    
    cin >> d;
    F0R(i, d){
        int k;
        cin >> k;
        used[k] = true;
        days[d-1-i] = mp(clb[k], pot[k]);
    }
    FOR(i, 1, n){
        if(!used[i]){
            e[pot[i]].pb(clb[i]);
        }
    }
    
    int mex = 0;
    while(chk(mex)){
        mex++;
    }
    F0R(i, d){
        ans[d-1-i] = mex;
        
        e[days[i].s].pb(days[i].f);
        //cout << days[i].s << " " << days[i].f << "\n";
        
        while(chk(mex)){
            mex++;
            //cout << "found, mex now " << mex << "\n";
        }
    }
    
    F0R(i, d){
        cout << ans[i] << "\n";
    }
    
    return 0;
}