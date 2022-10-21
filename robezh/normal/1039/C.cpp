#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)5e5 + 500;
const int mod = (int)1e9 + 7;

struct edge{
    ll key;
    int a, b;
    edge(ll _key, int _a, int _b){
        key = _key, a = _a, b = _b;
    }
};

bool cmp(edge e1, edge e2){
    return e1.key < e2.key;
}


int n,m,k;
ll num[N];
int f[N];
int pw2[N];
vector<edge> E;

int find(int u){return f[u] == u ? u : f[u] = find(f[u]);}
int unite(int u, int v){
    int fu = find(u), fv = find(v); f[fu] = fv;
}
bool same(int u, int v){return find(u) == find(v);}

int main(){
    pw2[0] = 1;
    for(int i = 1; i < N; i++) pw2[i] = 2 * pw2[i-1] % mod;

    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; i++) scanf("%I64d", &num[i]);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        ll key = num[a] ^ num[b];
        E.push_back(edge(key, a, b));
    }
    sort(E.begin(), E.end(), cmp);
    for(int i = 0; i < m-1; i++) assert(E[i].key <= E[i+1].key);
    ll res = 0;
    for(int i = 0; i < n; i++) f[i] = i;
    ll keycnt = (1LL << k);
    for(int i = 0; i < m;){

        int r = i;
        while(r < m && E[r].key == E[i].key) r++;
        int cmp = n;
        ll key = E[i].key;
        for(int j = i; j < r; j++){
            edge e = E[j];
            int a = e.a, b = e.b;

            if(!same(a, b)){
                cmp--;
                unite(a, b);
            }

        }
        res = (res + pw2[cmp]) % mod;
        keycnt --;
        for(int j = i; j < r; j++){
            edge e = E[j];
            f[e.a] = e.a, f[e.b] = e.b;
        }
        i = r;
    }
    res = (res + 1LL * pw2[n] * (keycnt % mod)) % mod;
    cout << res << endl;
}