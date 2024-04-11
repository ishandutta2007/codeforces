#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
int n , pre[N] , mcnt;
struct edge {
    int x , next;
} e[N << 1];

int deg[N];
bool f[N << 1];
int Hash[N << 1];
void addedge(int x , int y) {
    e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
}
map< vector<int> , int> HH;
int id(vector<int> V) {
    if (!HH.count(V)) {
        return HH[V] = HH.size();
    }
    return HH[V];
}

int dfs(int o) {
    if (f[o]) {
        return Hash[o];
    } f[o] = 1;
    int x = e[o].x;
    vector< int > V;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if ((i ^ o) != 1) {
            V.push_back(dfs(i));
        }
    }
    sort(V.begin() , V.end());
    return Hash[o] = id(V);
}

int main() {
    scanf("%d" , &n);
    memset(pre , -1,  sizeof(pre));
    for (int i = 0 ; i < n - 1 ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        addedge(x , y);
        addedge(y , x);
        ++ deg[x];
        ++ deg[y];
    }
    for (int i = 1 ; i <= n ; ++ i) {
        addedge(i + n , i);
    }
    vector<int> res;
    set<int> P;
    for (int i = 1 ; i <= n ; ++ i) {
        if (deg[i] + 1 <= 4) {
            int j = n * 2 + i - 3;
            //printf("%d %d\n" , j , e[j].x);
            P.insert(dfs(j));
            //cout << j << ' ' << dfs(j) << endl;
        }
    }
    cout << P.size() << endl;
}