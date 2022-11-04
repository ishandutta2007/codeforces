#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
const int N = 4e5 + 1;

int n, m, h[N], thre[N], f[N], g[N], stk[N], top;
vector<int> vec[N];

bool mustuse[N];
bool cmp(int a, int b){
    return a > b;
}
vector<int> qry[N];
int ans[N], a[N], b[N];

int main(){
    scanf("%d%d", &n, &m);
    int maxans = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d", &h[i]);
        f[i] = lower_bound(stk + 1, stk + 1 + top, h[i]) - stk;
        maxans = max(maxans, f[i]);
        stk[f[i]] = h[i];
        if(f[i] > top)
            top++;
    }
    thre[maxans] = 1e9;
    for (int i = n; i; i--){
        if(h[i] <= thre[f[i]]){
            vec[f[i]].push_back(i);
            thre[f[i] - 1] = max(thre[f[i] - 1], h[i] - 1);
        }
    }
    for (int i = 1; i <= maxans; i++){
        if(vec[i].size() == 1){
            mustuse[vec[i].front()] = true;
        }
    }
    for (int i = 1; i <= m; i++){
        scanf("%d%d", &a[i], &b[i]);
        qry[a[i]].push_back(i);
    }
    top = 0;
    for (int i = 1; i < n; i++){
        int pos = lower_bound(stk + 1, stk + 1 + top, h[i]) - stk;
        stk[pos] = h[i];
        if(pos > top)
            top++;
        for(auto id : qry[i + 1]){
            int h = b[id];
            ans[id] += lower_bound(stk + 1, stk + 1 + top, h) - stk - 1;
        }
    }
    top = 0;
    for (int i = n; i > 1; i--){
        int pos = lower_bound(stk + 1, stk + 1 + top, h[i], cmp) - stk;
        stk[pos] = h[i];
        if(pos > top)
            top++;
        for(auto id : qry[i - 1]){
            int h = b[id];
            ans[id] += lower_bound(stk + 1, stk + 1 + top, h, cmp) - stk - 1;
        }
    }
    for (int i = 1; i <= m; i++){
        printf("%d\n", max(ans[i] + 1, maxans - mustuse[a[i]]));
    }
    return 0;
}