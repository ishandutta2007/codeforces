#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;
const int BK = 100, BKSIZE = 1005;
const int SQRT = 317;
typedef pair<int, int> P;

int n;
vector<int> G[N];
int res[N];
int upp[N];
int fir[N], sec[N];
int ord[N], fa[N];
int T = 0;

void dfs(int v, int p){
    for(int nxt : G[v]) if(nxt != p) dfs(nxt, v);
    fa[v] = p;
    ord[T++] = v;
}

int get_res(int x){
    for(int i = 0; i < n; i++){
        int v = ord[i];
        int com = 0, mx1 = 0, mx2 = 0;
        for(int nxt : G[v]){
            if(nxt == fa[v]) continue;
            com += fir[nxt];
            if(sec[nxt] > mx1) mx2 = mx1, mx1 = sec[nxt];
            else if(sec[nxt] > mx2) mx2 = sec[nxt];
        }
        if(mx1 + mx2 >= x - 1) fir[v] = com + 1, sec[v] = 0;
        else fir[v] = com, sec[v] = mx1 + 1;
    }
    return fir[ord[n-1]];
}

int get_upp(int ans, int las){
    int l = 1, r = las + 1, mid;
    while(l + 1 < r){
        mid = (l + r) / 2;
        if(get_res(mid) >= ans) l = mid;
        else r = mid;
    }
    return l;
}


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 0);
    fill(res, res + n + 1, -1);
    for(int k = 1; k <= min(BKSIZE, n); k++){
        res[k] = get_res(k);
    }
    upp[0] = n;
    for(int i = 1; i <= BK; i++) upp[i] = get_upp(i, upp[i-1]);
//    for(int i = 1; i <=n; i++) cout << upp[i] << " ";
//    cout << endl;

    int cur = BK;
    for(int i = BKSIZE + 1; i <= n; i++){
        while(upp[cur] < i) cur--;
        res[i] = cur;
    }

    for(int i = 1; i <= n; i++) printf("%d\n", res[i]);

}