#include <bits/stdc++.h>
using namespace std;
#define inf 1e9

#define N 410

int dist[N], fl[N];

struct dat{
    int to, rev, f, cap, cost;
    dat(int to = 0, int rev = 0, int f = 0, int cap = 0, int cost = 0):to(to), rev(rev), f(f), cap(cap), cost(cost){}
};

vector<dat> v[N];
typedef pair<int, int> pi;
priority_queue<pi> q;
pi pa[N];

void add(int x, int y, int cap, int cost) {
    int n = v[x].size();
    int m = v[y].size();
    dat aa = dat(y, m, 0, cap, cost);
    v[x].push_back(aa);
    aa = dat(x, n, 0, 0, -cost);
    v[y].push_back(aa);
}

int so, de, mxflow, mncost;

void init() {
    mxflow = mncost = 0;
    for(int i = 0; i <= de; i ++) v[i].clear();
}

void doit() {
    while(1) {
        for(int i = 0; i <= de; i ++) dist[i] = inf, fl[i] = 0;
        dist[so] = 0, fl[0] = inf;
        while(!q.empty()) q.pop();
        q.push(pi(0, 0));
        while(!q.empty()) {
            pi aa = q.top();
            q.pop();
            if(aa.first != -dist[aa.second]) continue;
            int x = aa.second;
            for(int i = 0; i < v[x].size(); i ++) {
                dat ba = v[x][i];
                if(ba.f == ba.cap) continue;
                int y = ba.to;
                if(dist[y] > dist[x] + ba.cost) {
                    dist[y] = dist[x] + ba.cost;
                    fl[y] = min(fl[x], ba.cap - ba.f);
                    q.push(pi(-dist[y], y));
                    pa[y] = pi(x, i);
                }
            }
        }
        if(dist[de] == inf) break;
        int xx = de;
        mxflow += fl[de];
        while(1) {
            pi aa = pa[xx];
            int y = aa.first;
            int id = aa.second;
            mncost += v[y][id].cost * fl[de];
            v[y][id].f += fl[de];
            v[xx][v[y][id].rev].f -= fl[de];
            if(y == so) break;
            xx = y;
        }
    }
    return ;
}

set<pi> S;
set<pi> :: iterator it;
char s[100];
int A[N], B[N], ty[N];

int main() {
    //freopen("1.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) {
        scanf("%s%d", s, &A[i]);
        if(s[0] == 'A') ty[i] = 0;
        else ty[i] = 1;
    }
    for(int i = 1; i <= m; i ++) scanf("%d", &B[i]);
    so = 0;
    de = max(n, m) * 2 + 1;
    init();
    for(int i = 1; i <= m; i ++) add(so, i, 1, 0);
    for(int i = 1; i <= n; i ++) add(m + i, de, 1, 0);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(B[j] < A[i]) continue;
            if(ty[i] && B[j] > A[i]) add(j, m + i, 1, 0);
            else if(!ty[i]) {
                add(j, m + i, 1, A[i] - B[j]);
            }
        }
    }
    for(int i = 1; i <= m; i ++) add(i, de, 1, 0);
    doit();
    int va = -mncost;
    bool ok = true;
    for(int i = 1; i <= m; i ++) S.insert(pi(B[i], i));
    int sum = 0;
    for(int i = 1; i <= n; i ++) if(ty[i]) {
        it = S.lower_bound(pi(A[i] + 1, 0));
        if(it == S.end()) {
            ok = false;
            break;
        }
        S.erase(it);
    }
    for(int i = 1; i <= n; i ++) if(!ty[i]) {
        sum -= A[i];
        it = S.lower_bound(pi(A[i], 0));
        if(it == S.end()) {
            ok = false;
            break;
        }
        sum += (*it).first;
        S.erase(it);
    }
    for(it = S.begin(); it != S.end(); it ++) sum += (*it).first;
    if(ok) va = max(va, sum);
    printf("%d\n", va);
    return 0;
}