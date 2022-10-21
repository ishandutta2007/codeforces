#include <bits/stdc++.h>
using namespace std;

namespace fastIO {
#define BUF_SIZE 100000
    //fread -> read
    bool IOerror = 0;
    inline char nc() {
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
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    inline void read(int &x) {
        char ch;
        while(blank(ch = nc()));
        if(IOerror) return;
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    }
#undef BUF_SIZE
};
using namespace fastIO;

const int N = (int)1e6 + 500;

int n,a,b;
vector<int> G[N], num[N];
int idx[N], dom[N], dep[N];

void dfs(int v, int par){
    dep[v] = 0;
    int mxidx = -1;
    for(int nxt : G[v]){
        if(nxt == par) continue;
        dfs(nxt, v);
        if(dep[nxt] + 1 > dep[v]){
            mxidx = nxt, dep[v] = dep[nxt] + 1;
        }
    }

    if(mxidx != -1){
        idx[v] = idx[mxidx];
        dom[v] = dom[mxidx] + 1;
        num[idx[v]].push_back(1);
        int mxdom = num[idx[v]][dep[v]-dom[v]];
        if(mxdom == 1) dom[v] = 0;
        for(int nxt : G[v]){
            if(nxt == par || nxt == mxidx) continue;

            for(int i = 0; i < num[idx[nxt]].size(); i++){
                int j = dep[v]- (dep[nxt] + 1) + i;
                num[idx[v]][j] += num[idx[nxt]][i];
                if(num[idx[v]][j] > mxdom || (num[idx[v]][j] == mxdom && dep[v] - j < dom[v])){
                    mxdom = num[idx[v]][j]; dom[v] = dep[v] - j;
                }
            }
        }
    }
    else{
        dom[v] = 0;
        num[idx[v]].push_back(1);
    }

}


int main(){
    read(n);
    for(int i = 0; i < n-1; i++){
        read(a), read(b);
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < n; i++) idx[i] = i;
    dfs(0, -1);

    for(int i = 0; i < n; i++) printf("%d\n", dom[i]);
}