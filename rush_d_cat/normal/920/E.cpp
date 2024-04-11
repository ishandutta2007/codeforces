#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N = 4000000+10;
vector<int> ans;
struct edge {int v, nex;} edge[N];
struct link {int pre, nex;} L[N];
int n, m, x, y, cnt, head[N], vis1[N], vis2[N];
void init() {
    memset(head, -1, sizeof head); cnt = 0; 
    memset(vis1, 0, sizeof(vis1)); memset(vis2, 0, sizeof(vis2));

    for (int i = 1; i <= n; i ++) L[i].pre = i-1, L[i].nex = i+1; 
    L[n].nex = 0; L[0].nex = 1;
}
void del(int x) {
    L[L[x].nex].pre = L[x].pre;
    L[L[x].pre].nex = L[x].nex;
}
void add_adge(int u, int v) {
    edge[cnt].v = v; edge[cnt].nex = head[u]; head[u] = cnt ++;
}
void prt() {
    
}
int main() {
    scanf("%d %d", &n, &m); 
    init();
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d", &x, &y);
        add_adge(x, y); add_adge(y, x);
    }

    while (L[0].nex) {
        queue<int> que; 
        que.push(L[0].nex); vis2[L[0].nex] = 1; del(L[0].nex); 
        
        int cur = 1; 
        while (que.size()) {
            int u = que.front(); que.pop(); 
            //if (n == 200000 && m == 200000) printf("%d\n", u);
            for (int i = head[u]; i != -1; i = edge[i].nex) vis1[edge[i].v] = 1; 
            int cnt = 0;
            for (int i = L[0].nex; i != 0; i = L[i].nex) {
                cnt ++;
                if (vis1[i] == 0 && vis2[i] == 0) {
                    que.push(i); vis2[i] = 1; del(i);
                    cur ++;
                }
            }          
            //if(n==200000&&m==200000)printf("cnt = %d, cur = %d\n", cnt, cur);

            for (int i = head[u]; i != -1; i = edge[i].nex) vis1[edge[i].v] = 0;
            
        }
        //if (n == 200000 && m == 200000) printf("%d\n", cur);
        ans.push_back(cur);
    }

    printf("%d\n", (int)ans.size());
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i ++) 
        printf("%d ", ans[i]);
}