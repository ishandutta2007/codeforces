#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <time.h> 
using namespace std;
const int N = 1000005;

typedef pair<int, int> pii;
typedef long long LL;
int n, m, s, u[N], v[N], w[N], us[N], cmp[N];

vector<pii> G[N], rG[N];
vector<int> vs;

void dfs(int x) {
    us[x] = 1;
    for (int i = 0; i < G[x].size(); i ++) {
        if (!us[G[x][i].first]) dfs(G[x][i].first);
    }
    vs.push_back(x);
}

void rdfs(int x, int k) {
    us[x] = 1, cmp[x] = k;
    for (int i = 0; i < rG[x].size(); i ++) {
        if (!us[rG[x][i].first]) rdfs(rG[x][i].first, k);
    }
}

int scc() {
    memset(us, 0, sizeof(us));
    for (int i = 1; i <= n; i ++) {
        if (!us[i]) dfs(i);
    }
    int k = 0;
    memset(us, 0, sizeof(us));
    for (int i = (int)vs.size()-1;i>=0;i--) {
        if (!us[vs[i]]) rdfs(vs[i], k ++);
    }
    return k;
}

vector<pii> gragh[N];
LL weigh[N];

LL pre[20002], sum[20002];
void init() {
    for (LL x = 1; x <= 20000; x ++) 
        pre[x] = x * (x - 1) / 2;
    for (LL i = 1; i <= 20000; i ++)
        sum[i] = sum[i-1] + pre[i];
}


LL f(LL w) {
    if(w == 0) return 0;
    LL k = (sqrt(1 + 8 * w) - 1) / 2;
    k--;
    while(((k + 1) * (k + 2)) / 2 <= w) k++;

    return w + k * w - (((k + 1) * k * (k + 1)) / 2 - (k * (k + 1) * (2 * k + 1)) / 6);
}

clock_t start,finish;  
void test() {
    start=clock();
    for (LL i=100000000-1000000;i<=100000000;i++) {
        f(i);
    }
    finish=clock();     
    cout << finish-start   << "/" << CLOCKS_PER_SEC  << " (s) "<< endl; 
}

void make_gragh() {
    start=clock();  

    init();   
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
        G[u[i]].push_back(make_pair(v[i], w[i]));
        rG[v[i]].push_back(make_pair(u[i], w[i]));
    }
    scanf("%d", &s);
    scc(); 
 
    if(n==400000 && m==1000000) {
        finish=clock();     
        //cout << finish-start   << "/" << CLOCKS_PER_SEC  << " (s) "<< endl; 
    }

    for (int i = 1; i <= m; i ++) {
        if (cmp[u[i]] == cmp[v[i]])
            weigh[cmp[u[i]]] += f(w[i]);
        else
            gragh[cmp[u[i]]].push_back(make_pair(cmp[v[i]], w[i]));
        if (i % 100000 == 0 && n == 400000) {
            finish=clock();     
            //cout << finish-start   << "/" << CLOCKS_PER_SEC  << " (s) "<< endl;            
        }

    }

    if(n==400000 && m==1000000) {
        finish=clock();     
        //cout << finish-start   << "/" << CLOCKS_PER_SEC  << " (s) "<< endl; 
    }
}

LL a[N];
LL dp(int u) {
    if (a[u]) return a[u];
    LL ans = weigh[u];
    for (int i = 0; i < gragh[u].size(); i ++) {
        ans = max(ans, dp(gragh[u][i].first)+weigh[u]+gragh[u][i].second);
    }
    return a[u]=ans;
}

int main() {
    //test();
    make_gragh();
    //if(n==400000 && m==1000000) printf("ok\n");
    printf("%lld\n", dp(cmp[s]));
}