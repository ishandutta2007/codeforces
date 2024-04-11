#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500, sqr = 447;

struct query{
    int l, r, num, id;
};

bool cmp(query q1, query q2){
    return q1.l / sqr == q2.l / sqr ? q1.r < q2.r : q1.l < q2.l;
}

int n,m,a,b;
vector<int> G[N];
int c[N];
int timer = 0;
int l[N], r[N], eul[2*N];
query qry[N];
int cnt[N], suf[N];
int res[N];

void add(int c){
    int now = cnt[c];
    cnt[c]++;
    suf[now+1] ++;
}

void deadd(int c){
    int now = cnt[c];
    cnt[c]--;
    suf[now]--;
}

void dfs(int v, int p){
    l[v] = timer;
    eul[timer++] = c[v];
    for(int nxt : G[v]){
        if(nxt != p) dfs(nxt, v);
    }
    r[v] = timer;
    eul[timer++] = -1;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &c[i]);
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    for(int i = 0; i < m; i++){
        int v, c;
        scanf("%d%d", &v, &c);
        v--;
        qry[i].l = l[v], qry[i].r = r[v];
        qry[i].id = i, qry[i].num = c;
    }
    sort(qry, qry+m, cmp);

    fill(cnt, cnt+N, 0);
    int pl = 0, pr = -1;
    //for(int i = 0; i < n; i++) cout << r[i] << " ";
    //for(int i = 0; i < m; i++) cout << qry[i].r << " ";

    for(int i = 0; i < m; i++){
        int nl = qry[i].l, nr = qry[i].r;
        if(pl < nl){
            for(int j = pl; j < nl; j++) if(eul[j] != -1) deadd(eul[j]);
        }
        else{
            for(int j = nl; j < pl; j++) if(eul[j] != -1) add(eul[j]);
        }
        if(pr < nr){
            for(int j = pr+1; j <= nr; j++) if(eul[j] != -1) add(eul[j]);
        }
        else{
            for(int j = nr+1; j <= pr; j++) if(eul[j] != -1) deadd(eul[j]);
        }
        res[qry[i].id] = suf[qry[i].num];
        pl = nl, pr = nr;
    }
    for(int i = 0; i < m; i++) printf("%d\n", res[i]);


}