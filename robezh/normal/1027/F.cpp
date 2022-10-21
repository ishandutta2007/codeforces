#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 500;

int n;
int a[N], b[N];
int u[3*N], st[3*N], ed[3*N];
int mx1[3*N], mx2[3*N];
unordered_map<int, int> mp;

int find(int i){return u[i] == i ? i : u[i] = find(u[i]);}
int unite(int i, int j){
    i = find(i), j = find(j);
    u[j] = i;
    st[i] += st[j], ed[i] += ed[j];
    int m1 = max(mx1[i], mx1[j]), m2 = min(mx1[i], mx1[j]);
    mx1[i] = m1;
    mx2[i] = max(m2, max(mx2[i], mx2[j]));
}

int cnt;

int getid(int x){
    if(mp.count(x)) return mp[x];
    else{
        mx1[cnt] = x;
        mx2[cnt] = 0;
        ed[cnt] = 1;
        st[cnt] = 0;

        return mp[x] = cnt++;
    }
}

int main(){
    mp.reserve(1024);
    mp.max_load_factor(0.25);

    for(int i = 0; i < 3 * N; i++) u[i] = i;
    scanf("%d", &n);
    cnt = n;
    fill(st, st+n, 1);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &a[i], &b[i]);
        int ida = getid(a[i]), idb = getid(b[i]);
        if(find(i) != find(ida)) unite(i, ida);
        if(find(i) != find(idb)) unite(i, idb);
    }
    int res = 0;
    for(int i = 0; i < cnt; i++){
        if(find(i) != i) continue;
        if(st[i] > ed[i]) return !printf("-1");
        if(st[i] == ed[i]) res = max(res, mx1[i]);
        else res = max(res, mx2[i]);
    }
    printf("%d", res);
}