#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6 + 1, M = 1.5e7 + 1;

int n, m, C, c, len, k;
long long x, y, v[N];

struct node{
    int c;
    long long v;
    bool operator<(const node &b) const{
        return v != b.v ? v < b.v : c < b.c;
    }
}nd[M];

bool cmp(const node &a, const node &b){
    return a.v < b.v;
}

int main(){
    scanf("%d%d", &n, &C);
    for(int i = 1; i <= n; i++){
        scanf("%d%lld%lld", &c, &x, &y);
        v[c] = max(v[c], x * y);
    }
    for(int i = 1; i <= C; i++) if(v[i]){
        for(int j = 1; j * i <= C; j++){
            len++;
            nd[len].c = i * j;
            nd[len].v = j * v[i];
        }
    }
    sort(nd + 1, nd + 1 + len);
    for(int i = 1; i <= len; i++){
        while(nd[i].c <= nd[k].c) k--;
        if(nd[i].v > nd[k].v) nd[++k] = nd[i];
    }
    scanf("%d", &m);
    while(m--){
        scanf("%lld%lld", &x, &y);
        node nod;
        nod.v = x * y;
        int p = upper_bound(nd + 1, nd + 1 + k, nod, cmp) - nd;
        if(p == k + 1) puts("-1");
        else printf("%d\n", nd[p].c);
    }
    return 0;
}