#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
int n,m;
int L[1<<20], R[1<<20],valid[1<<20],szL,szR;
int x[10002],y[100002],mp[42][42];
int nex[20],banset[1<<20];
vector<int> g[42];
LL count_indepen() {
    int val = 0;
    for(int s=0;s<1<<szL;s++) {
        bool ok = 1;
        for(int i=0;i<szL;i++){
            if((s>>i&1)) {
                for(int j=0;j<szL;j++){
                    if(s>>j&1) {
                        if(mp[i][j]) ok = 0;
                    }
                }
            }
        }
        valid[s] = L[s] = ok;
        if(ok) val ++;
    }
    //printf("# %d\n", val);
    for (int bit = 0; bit < szL; bit ++) {
        for (int i = 1; i < (1<<szL); i ++) {
            if ( ((i>>bit) & 1) == 1 )
                L[i] += L[i^(1<<bit)];
        }
    }

    for(int s=0;s<1<<szR;s++) {
        bool ok = 1;
        for(int i=0;i<szR;i++){
            if((s>>i&1)) {
                for(int j=0;j<szR;j++){
                    if(s>>j&1) {
                        if(mp[i+szL][j+szL]) ok = 0;
                    }
                }
            }
        }
        //if (ok) printf("rig mask = %d\n", s);
        R[s] = ok;
    }
    for (int bit = 0; bit < szR; bit ++) {
        for (int i = 1; i < (1<<szR); i ++) {
            if ( ((i>>bit) & 1) == 1 )
                R[i] += R[i^(1<<bit)];
        }
    }

    for(int i=0;i<szL;i++) {
        for(int j=0;j<n;j++) {
            if(j>=szL && mp[i][j]) {
                nex[i] |= (1<<(j-szL));
            }
        }
    }
    for(int s=1;s<1<<szL;s++) {
        for(int i=0;i<szL;i++) {
            if(s>>i&1) {
                banset[s] = banset[s ^ (1<<i)] | nex[i];
            }
        }
        //printf("banset[%d] = %d\n", s, banset[s]);
    }

    LL res = 0;
    for(int s=0;s<1<<szL;s++) {
        if(valid[s]) {
            //printf("s = %d, ok = %d, cnt = %d\n", s, ((1<<szR) - 1) ^ banset[s], R[((1<<szR) - 1) ^ banset[s]]);
            int rigset = ((1<<szR) - 1) ^ banset[s];
            res = res + R[rigset];
        }
    }
    //res --; // substract no red point
    //printf("res = %lld\n", res);
    return res * 2;
}
int col[42], flag = 1;
void dfs(int u) {
    for(auto v: g[u]) {
        if (col[v] == 0) {
            col[v] = 3 - col[u];
            dfs(v);
        } else {
            if(col[v] == col[u]) flag = 0;
        }
    }
}

int par[42];
int find(int x) {
    return par[x] == x ? par[x] : par[x] = find(par[x]);
}
int deg[42];
int main() {
    for(int i=0;i<42;i++) par[i] = i;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x[i],&y[i]); --x[i], --y[i]; deg[x[i]] ++, deg[y[i]] ++;
        mp[x[i]][y[i]] = mp[y[i]][x[i]] = 1;
        g[x[i]].push_back(y[i]); g[y[i]].push_back(x[i]);
        par[find(x[i])] = find(y[i]);
    }
    szL = n >> 1;
    szR = n - szL;
    LL ans = 1LL << n;
    ans = ans - count_indepen();
    //cout << ans << endl;
    int cnt = 0, cnt2 = 0;
    for (int i=0;i<n;i++) {
        if(find(i) == i && deg[i] > 0) cnt ++;
        if(deg[i] == 0) cnt2 ++;
        if(col[i] == 0) {
            col[i] = 1;
            dfs(i);
        }
    }
    //printf("ans1 = %lld\n", ans);
    if(cnt)
        ans = ans - ((1LL << cnt) - 2) * (1LL << cnt2); 
    //printf("ans2 = %lld\n", ans);
    //printf("flag = %d\n", flag);
    if (flag == 1) ans = ans + (1LL << (cnt + cnt2));
    cout << ans << endl;
}