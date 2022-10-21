#include <bits/stdc++.h>
using namespace std;

const int N = (int)4e5 + 500;

int q;
int u[N], val[N];
map<int, int> mp;
int cnt = 0;

int getid(int x){
    if(mp.count(x)) return mp[x];
    return mp[x] = cnt++;
}

int find(int i){
    if(u[i] == i) return i;
    int nxt = find(u[i]);
    int new_val = (val[u[i]] ^ val[i]);
    u[i] = nxt;
    val[i] = new_val;
    return u[i];
}

void unite(int i, int j, int v){
    int ni = find(i), nj = find(j);
    v ^= val[i], v ^= val[j];
    u[ni] = nj;
    val[ni] = v;
}


int main(){
    for(int i = 0; i < N; i++) u[i] = i;

    scanf("%d", &q);
    int last = 0;
    while(q--){
        int t,l,r;
        scanf("%d%d%d", &t, &l, &r);
        l ^= last, r ^= last;
        if(l > r){int tmp = l; l = r, r = tmp;}
        r++;
        l = getid(l), r = getid(r);
        if(t == 1){
            int val;
            scanf("%d", &val);
            val ^= last;
            if(find(l) == find(r)) continue;
            unite(l, r, val);
        }
        else{
            int li = find(l), ri = find(r);
            int res = (li == ri ? (val[l] ^ val[r]) : -1);
            printf("%d\n", res);
            last = (res == -1 ? 1 : res);
        }
    }
}