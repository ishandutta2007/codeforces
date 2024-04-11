#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 100005
int n , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];
vector<int> res;
int a[N] , b[N];
int L[2];
void dfs(int x , int fa , int dep) {
    if (L[dep & 1]) {
        a[x] ^= 1;
    }
    if (a[x]) {
        L[dep & 1] ^= 1;
        res.push_back(x);
    }
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            dfs(y , x , dep + 1);
        }
    }
    if (a[x]) {
        L[dep & 1] ^= 1;
    }
    if (L[dep & 1]) {
        a[x] ^= 1;
    }
}

void work()
{
    int i , x , y;
    scanf("%d",&n);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&b[i]) , a[i] ^= b[i];

    dfs(1 , 0 , 0);
    printf("%d\n" , res.size());
    for (i = 0 ; i < res.size() ; ++ i) {
        printf("%d\n" , res[i]);
    }
}

int main()
{
    work();
    return 0;
}