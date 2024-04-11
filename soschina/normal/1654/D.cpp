#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 2e5 + 1, p = 998244353;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int fpow(int base, int t = p - 2){
    int ret = 1;
    while(t){
        if(t & 1) ret = 1ll * ret * base % p;
        base = 1ll * base * base % p;
        t >>= 1;
    }
    return ret;
}

int t, n, u, v, a, b, head[N], nxt[N << 1], to[N << 1], x[N << 1], y[N << 1], eid;

void addedge(int u, int v, int a, int b){
    to[eid] = v;
    x[eid] = a;
    y[eid] = b;
    nxt[eid] = head[u];
    head[u] = eid++;
}

int prime[N], last[N], len;
struct powerprime{
    int base, power;
    powerprime(int _base, int _power) : base(_base), power(_power){}
};
vector<powerprime> res[N];

int exp[N], now[N];

void dfs(int i, int f){
    for(int e = head[i]; e; e = nxt[e]) if(to[e] != f){
        for(powerprime &pp : res[y[e]])
            now[pp.base] -= pp.power;
        for(powerprime &pp : res[x[e]]){
            now[pp.base] += pp.power;
            exp[pp.base] = max(exp[pp.base], now[pp.base]);
        }
        dfs(to[e], i);
        for(powerprime &pp : res[y[e]])
            now[pp.base] += pp.power;
        for(powerprime &pp : res[x[e]])
            now[pp.base] -= pp.power;
    }
}

int getans(int i, int f, int val){
    int sum = val;
    for(int e = head[i]; e; e = nxt[e]) if(to[e] != f)
        sum = (sum + getans(to[e], i, 1ll * val * fpow(x[e]) % p * y[e] % p)) % p;
    return sum;
}

int main(){
    for(int i = 2; i < N; i++){
        if(!last[i]){
            prime[++len] = i;
            res[i].push_back(powerprime(i, 1));
        }
        for(int j = 1; j <= len && i * prime[j] < N; j++){
            last[i * prime[j]] = i;
            res[i * prime[j]] = res[i];
            if(i % prime[j] == 0){
                res[i * prime[j]].back().power++;
                break;
            }
            res[i * prime[j]].push_back(powerprime(prime[j], 1));
        }
    }
    scanf("%d", &t);
    while(t--){
        eid = 1;
        memset(exp + 1, 0, sizeof(int) * n);
        memset(head + 1, 0, sizeof(int) * n);
        scanf("%d", &n);
        for(int i = 1; i < n; i++){
            scanf("%d%d%d%d", &u, &v, &a, &b);
            int d = gcd(a, b);
            a /= d, b /= d;
            addedge(u, v, a, b);
            addedge(v, u, b, a);
        }
        dfs(1, 0);
        int num = 1;
        for(int i = 1; i <= n; i++)
            while(exp[i]--)
                num = 1ll * num * i % p;
        printf("%d\n", getans(1, 0, num));
    }
    return 0;
}