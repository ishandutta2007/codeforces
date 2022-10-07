#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)/2)
using namespace std;
int n, m, q;

int A[1000009],B[1000009];
vector<int> adj[1000009];
int arr[1000009],l[1000009],r[1000009],per[1000009],p[1000009], No[1000009],cor[1000009];
int P(int x){
    if(p[x] == x) return x;
    p[x] = P(p[x]);
    return p[x];

}
int c = 0;
void dfs(int x){
    if(x <= n) {arr[++c] = per[x], l[x] = c, r[x] = c;
    return;
    }
    l[x] = n, r[x] = 1;
    for(int y : adj[x]){
        dfs(y);
        l[x] = min(l[x], l[y]);
        r[x] = max(r[x], r[y]);

    }

}
set<pair<int,int> > S;
void rem(int x){
    S.erase(S.find({l[x], r[x]}));
    for(int y : adj[x]){
        S.insert({l[y], r[y]});
    }
}
struct node{
    int mx;
    node *L, *R;
    void upd(){
        this->mx = max(this->L->mx, this->R->mx);
    }
};
void build(node *&x, int l, int r){
    x = new node();
    if(l==r) {x->mx = arr[l]; return;}
    build(x->L,l,mid);
    build(x->R,mid+1,r);
    x->upd();
}
void upd(node *&x, int l, int r, int p){
    if(p < l || p > r) return;
    if(l == r){
        x ->mx = 0;
        return;
    }
    upd(x->L,l,mid,p);
    upd(x->R,mid+1,r,p);
    x->upd();
}
int cnt(node *&x, int l, int r, int a, int b){
    if(l > b || r  < a) return 0;
    if(l >= a && r <= b) return x->mx;
    return max(cnt(x->L,l,mid,a,b),
               cnt(x->R,mid+1,r,a,b));


}
main(){
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= n; i++){
        scanf("%d", &per[i]);
        cor[per[i]] = i;
    }
    for(int i = 1; i <= m; i++){
         scanf("%d %d", &A[i], &B[i]);
    }
    int Z = m;
    vector<pair<int,int> > Q;
    for(int i = 1; i <= q; i++){
        int t;
        scanf("%d", &t);
        if(t == 1){
            int v;

            scanf("%d", &v);
            Q.push_back({v, Z});
        }
        else {
            int i;

            scanf("%d", &i);
            No[i] = Z;
            Z--;
        }
    }
    vector<pair<int,int> > O;
    for(int i = 1; i <= m; i++){
        O.push_back({No[i],i});
    }
    sort(O.begin(), O.end());
    for(int i = 1; i <= n+m+1; i++){
        p[i] = i;

    }
    for(int i = 0; i < m; i++){
        int x = O[i].second;
        int u = P(A[x]), v = P(B[x]);
        if(u == v) continue;
        p[u] = n + i + 1, p[v] = n + i + 1;
        adj[n+i+1].push_back(u);
        adj[n+i+1].push_back(v);
    }
     adj[n+m+1].push_back(P(1));
    for(int i = 1; i < n; i++){

        int u = P(i), v = P(i+1);
        if(u == v) continue;
        p[u] = n+m+1, p[v] = n+m+1;
        adj[n+m+1].push_back(v);
    }
    dfs(n+m+1);
    S.insert({1,n});
    int mx = n + m + 1;
    node *rt;
    build(rt, 1, n);
    for(int i = 0; i < Q.size(); i++){
        int v = Q[i].first, z = Q[i].second;
        while(mx > n + z){
            if(!l[mx]) {mx--; continue;}
            rem(mx);
            mx--;

        }

        auto it = S.lower_bound({l[v]+1, -1});
        it--;
        int L = it->first, R = it->second;
        int u = cnt(rt, 1, n, L, R);
        printf("%d\n", u);
        int ind = l[cor[u]];
        upd(rt,1,n, ind);

    }



}/*

5 5 5
1 2 3 4 5
1 2
2 3
3 4
4 5
5 1
1 1
2 1
2 2
1 5
1 1*/