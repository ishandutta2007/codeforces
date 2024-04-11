#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;
#define N 200011
#define ll long long

struct dat{
    ll a, b;
    int pos;
    dat(ll a = 0, ll b = 0, int pos = 0): a(a), b(b), pos(pos){}
}p[N];

bool cmp(dat p, dat q){
    if(p.a != q.a) return p.a < q.a;
    return p.b < q.b;
}

int T, n;
bool vis[N];

int main(){
    //freopen("c.in", "r", stdin);
    for(scanf("%d", &T); T--;){
        scanf("%d", &n);
        ll tota = 0, totb = 0;
        for(int i=0; i<2*n-1; i++){
            scanf("%I64d %I64d", &p[i].a , &p[i].b);
            p[i].pos = i+1;
            tota += p[i].a, totb += p[i].b;
        }
        sort(p, p+2*n-1, cmp);
        memset(vis, 0, sizeof(vis));

        puts("YES");
        vis[p[2*n-2].pos] = 1;
        for(int i=0; i<2*n-2; i+=2){
            if(p[i].b < p[i+1].b) vis[p[i+1].pos] = 1;
            else vis[p[i].pos] = 1;
        }
        for(int i=1; i<2*n; i++) if(vis[i]) printf("%d ", i); puts("");
    }
    return 0;
}