#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <set>
using namespace std;
typedef long long LL;
const int N = 200005;
const int Q = 1e9 + 7;

int n , m;
vector<int> e[N];
int f[N] , deg[N];
int main() {
    LL res = 0;
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < m ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        ++ deg[x] , ++ deg[y];
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 1 ; i <= n ; ++ i) {
        for (auto &y : e[i]) {
            f[i] = max(f[i] , f[y]);
        }
        ++ f[i];
        res = max(res , (LL)f[i] * deg[i]);
    }
    cout << res << endl;
    return 0;
}