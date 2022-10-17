#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 200005;

bool seen[2*MAXN];
int ways[2*MAXN];

int ans[MAXN];
int zer[MAXN];

int N;
vector<pair<int, int> > adj[MAXN];

int mult(int a, int b){
    return (a * 1ll * b) % MOD;
}

int mod_pow(int b, int e = MOD-2){
    if(e == 0) return 1;
    int h = mod_pow(mult(b, b), e/2);
    return (e%2) ? mult(h, b) : h;
}

void mult_ans(int i, int v){
    v %= MOD;
    if(v == 0) zer[i]++;
    else ans[i] = mult(ans[i], v); 
}

int div_ans(int i, int v){
    if(zer[i] > 1) return 0;
    if(zer[i] == 1) return v ? 0 : ans[i];
    return mult(ans[i], mod_pow(v));
}

int calc(int sti, int loc, int par){
    if(seen[sti]) return ways[sti]; 
    ways[sti] = 1;
    seen[sti] = true;

    for(auto p : adj[loc]){
        if(p.first == par) continue;
        int chw = calc(p.second, p.first, loc);
        ways[sti] = mult(ways[sti], (chw+1) % MOD);
    }

    mult_ans(par, (1+ways[sti])%MOD);
    return ways[sti];
}

void calc2(int loc, int par){
    for(auto p : adj[loc]){
        if(p.first == par) continue;
        int chw = ways[p.second];
        ways[p.second^1] = div_ans(loc, (1+chw)%MOD);
        mult_ans(p.first, (1+ways[p.second^1]%MOD));
    }

    for(auto p : adj[loc])
        if(p.first != par)
            calc2(p.first, loc);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=1, j=0; i<N; i++){
        int tmp; cin >> tmp;
        adj[tmp-1].emplace_back(i, j++);
        adj[i].emplace_back(tmp-1, j++);
    }

    for(int i=0; i<N; i++) ans[i] = 1;

    for(auto p : adj[0])
        calc(p.second, p.first, 0);
    
    calc2(0, -1);

    for(int i=0; i<N; i++)
        printf("%d ", zer[i] ? 0 : ans[i]);
    printf("\n");
}