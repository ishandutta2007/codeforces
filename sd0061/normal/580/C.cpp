#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , m , a[N] , res;
vector<int> e[N];
bool f[N];
void dfs(int x , int fa , int sum) {
    if (sum > m) f[x] |= 1;
    int c = 0;
    for (auto &y : e[x]) {
        if (y != fa) {
            f[y] |= f[x];
            if (a[y])
                dfs(y , x , sum + 1);
            else
                dfs(y , x , 0);
            ++ c;
        }
    }
    if (!c && !f[x])
        ++ res;
}

int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 1 ; i <= n ; ++ i)
        scanf("%d" , &a[i]);
    for (int i = 1 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[x].push_back(y);
        e[y].push_back(x);        
    }
    dfs(1 , 0 , a[1]);
    cout << res << endl;
    return 0;
}