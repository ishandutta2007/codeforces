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
#define BAD 96618
#define BAD2 146505
bool deb;
int n, k, dia;
vi e[MN];
pii gf(int cn, int p){
    int fn = cn, d = 0;
    F0R(i, e[cn].size()){
        int nn = e[cn][i];
        if(nn == p) continue;
 
        pii res = gf(nn, cn);
        if(res.s > d){
            fn = res.f;
            d = res.s;
        }
    }
    return mp(fn, d+1);
}
int d[MN];
int p[MN];
int dp[MN]; //longest path going down

int bst[MN][3];
void ab(int i, int x){
    if(deb && i == BAD2) cout << "adding " << x << "\n";
    if(x > bst[i][0]) swap(x, bst[i][0]);
    if(x > bst[i][1]) swap(x, bst[i][1]);
    if(x > bst[i][2]) swap(x, bst[i][2]);
}

int cs[MN];

void dfs(int cn){
    F0R(i, e[cn].size()){
        int nn = e[cn][i];
        if(nn == p[cn]) continue;

        p[nn] = cn;
        d[nn] = d[cn]+1;
        dfs(nn);
        ab(cn, dp[nn]+1);
    }
    dp[cn] = max(0, bst[cn][0]);
    //cout << "dp " << cn << " is " << dp[cn] << "\n";
    if(d[cn] != 0) ab(cn, d[cn]);
    //cout << "bst " << cn << " is " << bst[cn][0] << " " << bst[cn][1] << " " << bst[cn][2] << "\n";
    if(bst[cn][1]+bst[cn][2] >= k-1){
        cout << "No\n";
        if(deb){
            cout << "broke at " << cn << "\n";
            cout << bst[cn][0] << " " << bst[cn][1] << " " << bst[cn][2] << "\n";
        }
        exit(0);
    }
}

void col(int cn, int dif){ //0 = dia, -1 = top half, 1 = bot half
    if(dif != 0){
        F0R(i, e[cn].size()){
            int nn = e[cn][i];
            if(nn == p[cn]) continue;

            cs[nn] = (cs[cn]+dif+k)%k;
            col(nn, dif);
        }
        return;
    }

    int mx = 0;
    F0R(i, e[cn].size()){
        int nn = e[cn][i];
        if(nn == p[cn]) continue;

        if(dp[nn] > dp[mx]) mx = nn;
    }
    //cout << mx << "\n";
    F0R(i, e[cn].size()){
        int nn = e[cn][i];
        if(nn == p[cn]) continue;

        if(nn == mx){
            cs[nn] = (cs[cn]+1)%k;
            col(nn, dif);
        } else{
            //cout << cn << " " << nn << "\n";
            if(d[cn] < dia/2){
                cs[nn] = (cs[cn]-1+k)%k;
                col(nn, -1);
            } else{
                cs[nn] = (cs[cn]+1)%k;
                col(nn, 1);
            }
        }
    }
}

void alt(int cn, int p){
    F0R(i, e[cn].size()){
        int nn = e[cn][i];
        if(nn == p) continue;
        cs[nn] = !cs[cn];
        alt(nn, cn);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(bst, -0x3f, sizeof bst);

    cin >> n >> k;
    F0R(i, n-1){
        int u, v;
        cin >> u >> v;
        //u = i+1; v = i+2;
        //if(!i && u==BAD) deb = true;
        //deb = true;
        e[u].pb(v);
        e[v].pb(u);
    }
    //cout << "hmm\n";
    if(k == 2){
        alt(1, 0);
        cout << "YES\n";
        FOR(i, 1, n){
            cout << cs[i]+1 << " ";
        }
        return 0;
    }

    pii far = gf(1, 0);
    pii far2 = gf(far.f, 0);
    dia = far2.s;

    //cout << "dbl hmm\n";

    if(deb) cout << "root at " << far.f << "\n";
    dfs(far.f);
    /*FOR(i, 1, n){
        cout << dp[i] << " ";
    }
    cout << "\n";*/
    cs[far.f] = 0;
    dp[0] = -1;
    col(far.f, 0);

    cout << "YES\n";
    FOR(i, 1, n){
        cout << cs[i]+1 << " ";
    }
    
    return 0;
}