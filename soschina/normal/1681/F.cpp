#include <cstdio>
using namespace std;
const int N = 5e5 + 1;

namespace fastIO {
    #define BUF_SIZE 10000000
    //fread -> read
    bool IOerror = 0;
    char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if(p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if(pend == p1) {
                IOerror = 1;
                return -1;
            }
        }
        return *p1++;
    }
    bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    void rd(int &x) {
        char ch;
        while(blank(ch = nc()));
        if(IOerror) return;
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    }
    #undef BUF_SIZE
};
using namespace fastIO;


int n, head[N], nxt[N << 1], to[N << 1], val[N << 1], eid = 2;
void addedge(int u, int v, int w){
    to[eid] = v;
    val[eid] = w;
    nxt[eid] = head[u];
    head[u] = eid++;
}

int u, v, w, fa[N], sz[N], cntp[N][2], cntc[N][2];
long long ans;

void dfs(int i, int pre){
    sz[i] = 1;
    int tmp = fa[val[pre]];
    fa[val[pre]] = i;
    for (int e = head[i]; e; e = nxt[e])
        if((e ^ 1) != pre){
            dfs(to[e], e);
            sz[i] += sz[to[e]];
        }
    fa[val[pre]] = tmp;
    if(i == 1){
        for (int c = 1; c <= n; c++){
            cntc[c][0] += n;
            ans += 1ll * cntc[c][0] * cntc[c][1];
        }
    }
    else{
        cntp[i][0] += sz[i];
        ans += 1ll * cntp[i][0] * cntp[i][1];
        if(fa[val[pre]]){
            cntp[fa[val[pre]]][1] += cntp[i][0];
            cntp[fa[val[pre]]][0] -= sz[i];
        }
        else{
            cntc[val[pre]][1] += cntp[i][0];
            cntc[val[pre]][0] -= sz[i];
        }
    }
}

int main(){
    rd(n);
    for (int i = 1; i < n; i++){
        rd(u), rd(v), rd(w);
        addedge(u, v, w);
        addedge(v, u, w);
    }
    dfs(1, 0);
    printf("%lld", ans);
    return 0;
}