#include <iostream>
#include <vector>
using namespace std;
const int N = 1000000 + 10;
int dep[N];
struct Nod {
    int type;
    int val;
    int f0, f1;
} nod[N];

int n;
bool res[N][22][2];
int par[N][22];
vector<int> g[N];

void dfs(int u, int p) {
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    if(g[u].size()==0) {
        return;
    }
    if(g[u].size()==1) {
        dfs(g[u][0], u);
        nod[u].val = (!nod[g[u][0]].val);
        nod[g[u][0]].f0 = 1;
        nod[g[u][0]].f1 = 0;
    }
    if(g[u].size()==2) {
        dfs(g[u][0], u);
        dfs(g[u][1], u);
        if(nod[u].type == 0) {
            nod[u].val = (nod[g[u][0]].val & nod[g[u][1]].val);
            nod[g[u][0]].f0 = (0 & nod[g[u][1]].val);
            nod[g[u][0]].f1 = (1 & nod[g[u][1]].val);
            nod[g[u][1]].f0 = (0 & nod[g[u][0]].val);
            nod[g[u][1]].f1 = (1 & nod[g[u][0]].val);       
        }
        if(nod[u].type == 1) {
            nod[u].val = (nod[g[u][0]].val | nod[g[u][1]].val);
            nod[g[u][0]].f0 = (0 | nod[g[u][1]].val);
            nod[g[u][0]].f1 = (1 | nod[g[u][1]].val);
            nod[g[u][1]].f0 = (0 | nod[g[u][0]].val);
            nod[g[u][1]].f1 = (1 | nod[g[u][0]].val);  
        }
        if(nod[u].type == 2) {
            nod[u].val = (nod[g[u][0]].val ^ nod[g[u][1]].val);
            nod[g[u][0]].f0 = (0 ^ nod[g[u][1]].val);
            nod[g[u][0]].f1 = (1 ^ nod[g[u][1]].val);
            nod[g[u][1]].f0 = (0 ^ nod[g[u][0]].val);
            nod[g[u][1]].f1 = (1 ^ nod[g[u][0]].val);          
        }
    }


}

void init() {
    for(int i=1;i<=n;i++) {
        res[i][0][0] = nod[i].f0;
        res[i][0][1] = nod[i].f1;
    }
    //printf("!!! %d\n", res[2][0][1]);
    for(int i=1;i<=20;i++) {
        for(int j=1;j<=n;j++) {
            par[j][i] = par[par[j][i-1]][i-1];

            if (res[j][i-1][0] == 0) {

                res[j][i][0] = res[par[j][i-1]][i-1][0];
                
            }

            if (res[j][i-1][0] == 1) {
                res[j][i][0] = res[par[j][i-1]][i-1][1];
            }

            if (res[j][i-1][1] == 0) {
                res[j][i][1] = res[par[j][i-1]][i-1][0];
            }

            if (res[j][i-1][1] == 1) {
                res[j][i][1] = res[par[j][i-1]][i-1][1];
            }


        }
    }
    //printf("!!! %d\n", res[2][0][1]);
}

int query(int x) {
    //printf("x = %d\n", x);
    int tmp = (nod[x].val ^ 1);
    for(int i=20;i>=0;i--) {
        if (par[x][i] != 1) {
            tmp = res[x][i][tmp];
            //printf("i=%d, tmp=%d", i, tmp);
            x = par[x][i];
            //printf(", pos=%d\n",x);
        }    
    }
    //printf("res[%d][%d][%d] = %d\n", x,0,tmp,res[x][0][tmp]);
    tmp = res[x][0][tmp];
    return tmp;
}

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        char op[5]; scanf("%s", op);
        if(op[0]=='A') {
            nod[i].type = 0;
            int x, y; scanf("%d %d",&x,&y);
            g[i].push_back(x); 
            g[i].push_back(y);
        }
        if(op[0]=='O') {
            nod[i].type = 1;
            int x, y; scanf("%d %d",&x,&y);
            g[i].push_back(x); 
            g[i].push_back(y);
        }
        if(op[0]=='X') {
            nod[i].type = 2;
            int x, y; scanf("%d %d",&x,&y);
            g[i].push_back(x); 
            g[i].push_back(y);
        }    
        if(op[0]=='N') {
            nod[i].type = 3;
            int x; scanf("%d",&x);
            g[i].push_back(x); 
        }
        if(op[0]=='I') {
            int x; scanf("%d",&x);
            nod[i].type = 4; nod[i].val = x;
        }
    }

    dfs(1, 1);
    init();
    //printf("%d\n", res[10][0][0]);
    //for(int i=0;i<=2;i++)
    //printf("%d\n", res[2][i][0]);
    
    for(int i=1;i<=n;i++) {
        if(nod[i].type == 4) {
            printf("%d",query(i));
        }
    }
    
    /*
    for(int i=1;i<=n;i++) {
        printf("%d %d %d\n", i, res[i][1][0], res[i][1][1]);
    }
    */
}