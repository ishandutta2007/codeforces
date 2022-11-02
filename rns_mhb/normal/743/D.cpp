#include<bits/stdc++.h>
using namespace std;

#define N 200020
typedef long long LL;

vector <int> v[N];
int g[N];

const LL INF = 1ll << 60;

struct data{
    data(){};
    data(LL _sum = 0, LL _maxi = 0, LL _res = 0) : sum(_sum), maxi(_maxi), res(_res){};
    LL sum;
    LL maxi;
    LL res;
};

data dfs(int cur, int pre){
    LL max1 = -INF, max2 = -INF;
    LL sum = g[cur];
    LL max_cur;
    LL ret = -INF;
    for(auto x : v[cur]){
        if(x == pre) continue;
        data tmp = dfs(x, cur);
        if(tmp.maxi > max1){  max2 = max1; max1 = tmp.maxi; }
        else if(tmp.maxi > max2){ max2 = tmp.maxi; }
        sum += tmp.sum;
        ret = max(ret, tmp.res);
    }
    if(max2 != -INF) ret = max(ret, max1 + max2);
    max1 = max(sum, max1);
    return data(sum, max1, ret);
}

int n;

int main(){
   //freopen("d4.in", "r", stdin);
    int x, y;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", g + i);
    for(int i = 1; i < n; i ++){
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    data ans = dfs(1, 0);
    if(ans.res == -INF){ puts("Impossible"); return 0; }
    cout << ans.res << endl;
}