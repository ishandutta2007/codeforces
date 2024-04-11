#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<long long> > vvll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=(0); i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 2005
ll p2[MN];

string s;
int sl;
int n; //nodes: 1 to sl a, sl+1 to n-2 b, n-1 0, n 1

int ccc;
vi e[MN][2]; //sm, dif
int cc[MN];
vi cge[MN];
int cgs[MN];

void ae(int x, int y, int t){
    //cout << "ae " << x << " " << y << " " << t << "\n";
    e[x][t].pb(y);
    e[y][t].pb(x);
}

void dfs1(int cn){
    if(cc[cn] != 0) return;
    cc[cn] = ccc;
    F0R(i, e[cn][0].size()){
        int nn = e[cn][0][i];
        dfs1(nn);
    }
}
bool getCCs(){
    ccc = 0;
    FOR(i, 1, n){
        if(cc[i] == 0){
            ccc++;
            dfs1(i);
        }
        //cout << i << " in cc " << cc[i] << "\n";
    }
    FOR(i, 1, n){
        int c = cc[i];
        F0R(j, e[i][1].size()){
            int o = cc[e[i][1][j]];
            //cout << c << " " << o << "\n";
            if(c == o) return false;
            cge[c].pb(o);
            //cge[o].pb(c);
        }
    }
    return true;
}

bool dfs2(int cn, int val){
    if(cgs[cn] == val) return true;
    if(cgs[cn] != -1 && cgs[cn] != val) return false;
    
    cgs[cn] = val;
    F0R(i, cge[cn].size()){
        int nn = cge[cn][i];
        if(!dfs2(nn, !val)) return false;
    }
    return true;
}
int cntBip(){
    int cnt = 0;
    FOR(i, 1, ccc){
        if(cgs[i] == -1){
            cnt++;
            if(!dfs2(i, 0)) return -1;
        }
    }
    return cnt-1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    p2[0] = 1;
    FOR(i, 1, MN-2){
        p2[i] = (p2[i-1]*2)%MOD;
    }
    
    ll sm = 0;
    
    cin >> s;
    sl=s.length();
    reverse(s.begin(), s.end());
    //cout << s << "\n";
    FOR(k, 1, sl-1){
        //cout << "checking len " << k << "\n";
        F0R(j, MN-1){
            e[j][0].clear();
            e[j][1].clear();
            cge[j].clear();
        }
        memset(cc, 0, sizeof cc);
        memset(cgs, -1, sizeof cgs);
        
        n = sl + k + 2;
        ae(n-1, n, 1);
        ae(1, n, 0);
        ae(sl+1, n, 0);
        FOR(i, 1, sl){
            int j = (sl+1)-i;
            if(i < j) ae(i, sl+1-i, 0);
        }
        FOR(i, sl+1, n-2){
            int j = (sl+n-1)-i;
            if(i < j) ae(i, j, 0);
        }
        
        FOR(i, 1, sl){
            if(s[i-1]=='0'){
                if(i > k){
                    ae(i, n-1, 0);
                } else{
                    int o = sl + i;
                    ae(i, o, 0);
                }
            } else if(s[i-1]=='1'){
                if(i > k){
                    ae(i, n, 0);
                } else{
                    int o = sl+i;
                    ae(i, o, 1);
                }
            }
        }
        
        if(!getCCs()){
            continue;
        }
        int amt = cntBip();
        if(amt == -1) continue;
        sm = (sm+p2[amt])%MOD;
        //cout << k << " " << amt << "\n";
    }
    
    cout << sm << "\n";
    return 0;
}