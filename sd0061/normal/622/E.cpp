#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 500005;
const int Q = 1e9 + 7;
typedef long long LL;

int n;
vector<int> e[N]; 

void dfs(int x , int fa , int dep , vector<int> &leaf) {
    int ch = 0;
    for (auto &it : e[x])
        if (it != fa) {
            ++ ch;
            dfs(it , x , dep + 1 , leaf);
        }
    if (!ch)
        leaf.push_back(dep);
}

int cal(int x) {
    vector<int> leaf;
    dfs(x , 1 , 0 , leaf);
    sort(leaf.begin() , leaf.end());
    for (int i = 1 ; i < leaf.size() ; ++ i)
        leaf[i] = max(leaf[i] , leaf[i - 1] + 1);
    return leaf.back();
}

void work() {
    scanf("%d" , &n);
    for (int i = 1 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int res = 0;
    for (auto &it : e[1])
        res = max(res , cal(it) + 1);
    printf("%d\n" , res);
}

int main() {
    work();
    return 0;
}