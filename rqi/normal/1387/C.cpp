#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define bk back()
#define sz(x) (int)(x).size()

const ll MX = (1ULL<<63)-1;

ll trans[105][55][55]; //matrices
vi sing[105]; // node relies on i
vpi doubf[105]; // f relies on (i, s)
vpi doubs[105]; // f relies on (s, i)

ll comb(ll a, ll b){
    if(a == -1 || b == -1) return -1;
    if(a > MX-b) return -1;
    return a+b;
}

bool cmp(ll a, ll b){ //a < b
    if(a == b) return 0;
    if(a == -1) return 0;
    if(b == -1) return 1;
    return a < b;
}

int suf[55];
int to[55][2];
int TO[55][2];
bool bad[55];

pi par[55];
int cnt = 0;

void AhoInsert(vi c){
    int cur = 0;
    for(auto u: c){
        if(to[cur][u] == -1){
            to[cur][u] = ++cnt;
            par[cnt] = mp(cur, u);
        }
        cur = to[cur][u];
    }
    bad[cur] = 1;
}

int go(int node, int t);

int getLink(int node){
    if(suf[node] != -1) return suf[node];
    if(node == 0 || par[node].f == 0){
        suf[node] = 0;
    }
    else{
        suf[node] = go(getLink(par[node].f), par[node].s);
    }
    return suf[node];
}

int BAD[55];

bool isBad(int node){
    if(node == -2) return 1;
    if(BAD[node] != -1){
        return BAD[node];
    }
    if(node == 0){
        BAD[node] = 0;
    }
    else if(bad[node]){
        BAD[node] = 1;
    }
    else{
        BAD[node] = isBad(getLink(node));
    }
    return BAD[node];
}

int go(int node, int t){
    if(node == -2) return -2;
    if(TO[node][t] != -1){
        return TO[node][t];
    }

    if(to[node][t] != -1){
        if(isBad(to[node][t])){
            TO[node][t] = -2;
        }
        else{
            TO[node][t] = to[node][t];
        }
    }
    else if(node == 0){
        TO[node][t] = 0;
    }
    else{
        if(isBad(getLink(node))){
            TO[node][t] = -2;
        }
        else TO[node][t] = go(getLink(node), t);
    }
    return TO[node][t];
}

void genAho(){
    for(int i = 0; i <= cnt; i++){
        for(int j = 0; j < 2; j++){
            go(i, j);
        }
    }
}

int main(){
    for(int i = 0; i < 55; i++){
        suf[i] = -1;
        BAD[i] = -1;
        for(int j = 0; j < 2; j++){
            TO[i][j] = to[i][j] = -1;
        }
    }
    int G, N, M;
    cin >> G >> N >> M;

    int matind = G-1;

    for(int i = 1; i <= N; i++){
        int a, k;
        cin >> a >> k;
        vi B;
        for(int j = 1; j <= k; j++){
            int BB;
            cin >> BB;
            B.pb(BB);
        }

        if(sz(B) == 1){
            sing[B[0]].pb(a);
        }
        else if(sz(B) == 2){
            doubf[B[0]].pb(mp(a, B[1]));
            doubs[B[1]].pb(mp(a, B[0]));   
        }
        else{
            matind++;
            doubf[B[0]].pb(mp(matind, B[1]));
            doubs[B[1]].pb(mp(matind, B[0]));
            for(int i = 2; i < sz(B)-1; i++){
                matind++;
                doubf[matind-1].pb(mp(matind, B[i]));
                doubs[B[i]].pb(mp(matind, matind-1));
            }
            doubf[matind].pb(mp(a, B.bk));
            doubs[B.bk].pb(mp(a, matind));
        }
    }

    for(int i = 1; i <= M; i++){
        vi c;
        int l;
        cin >> l;
        for(int j = 1; j <= l; j++){
            int C;
            cin >> C;
            c.pb(C);
        }
        AhoInsert(c);
    }


    genAho();
    // for(int i = 0; i <= cnt; i++){
    //     cout << i << " " << suf[i] << " " << to[i][0] << " " << to[i][1] << " " << TO[i][0] << " " << TO[i][1] << "\n";
    // }

    for(int i = 0; i <= matind; i++){
        for(int j = 0; j <= cnt; j++){
            for(int k = 0; k <= cnt; k++){
                trans[i][j][k] = -1;
            }
        }
    }

    priority_queue<pair<ll, vi>, vector<pair<ll, vi>>, greater<pair<ll, vi>>> pq;

    for(int i = 0; i <= cnt; i++){
        for(int j = 0; j < 2; j++){
            if(TO[i][j] != -2){
                trans[j][i][TO[i][j]] = 0;
                //cout << j << " " << i << " " << TO[i][j] << "\n";
                pq.push(mp(0, vi{j, i, TO[i][j]}));
                //trans[j][i][to[i][j]] = 1;
            }
        }
    }

    while(sz(pq)){
        pair<ll, vi> p = pq.top();
        pq.pop();
        if(trans[p.s[0]][p.s[1]][p.s[2]] < p.f) continue;

        for(auto u: sing[p.s[0]]){
            if(cmp(p.f, trans[u][p.s[1]][p.s[2]])){
                trans[u][p.s[1]][p.s[2]] = p.f;
                pq.push(mp(p.f, vi{u, p.s[1], p.s[2]}));
            }
        }
        for(auto u: doubf[p.s[0]]){
            for(int i = 0; i <= cnt; i++){
                if(cmp(comb(comb(trans[p.s[0]][p.s[1]][p.s[2]], trans[u.s][p.s[2]][i]), 1), trans[u.f][p.s[1]][i])){
                    trans[u.f][p.s[1]][i] = comb(comb(trans[p.s[0]][p.s[1]][p.s[2]], trans[u.s][p.s[2]][i]), 1);
                    pq.push(mp(trans[u.f][p.s[1]][i], vi{u.f, p.s[1], i}));
                }
            }
        }
        for(auto u: doubs[p.s[0]]){
            for(int i = 0; i <= cnt; i++){
                if(cmp(comb(comb(trans[u.s][i][p.s[1]], trans[p.s[0]][p.s[1]][p.s[2]]), 1), trans[u.f][i][p.s[2]])){
                    trans[u.f][i][p.s[2]] = comb(comb(trans[u.s][i][p.s[1]], trans[p.s[0]][p.s[1]][p.s[2]]), 1);
                    pq.push(mp(trans[u.f][i][p.s[2]], vi{u.f, i, p.s[2]}));
                }
            }
        }
    }

    for(int i = 2; i <= G-1; i++){
        ll ans = -1;
        for(int j = 0; j <= cnt; j++){
            if(cmp(trans[i][0][j], ans)){
                ans = trans[i][0][j];
            }
        }
        if(ans == -1){
            cout << "YES" << "\n";
        }
        else cout << "NO" << " " << ans+1 << "\n";
    }

}