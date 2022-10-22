#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , m;
int X[N] , Y[N];
int deg[N];
vector<int> e[N];
bool check(int s) {
    queue<int> Q;
    memset(deg , 0 , sizeof(deg));
    for (int i = 1 ; i <= n ; ++ i)
        e[i].clear();
    for (int i = 0 ; i < s ; ++ i) {
        ++ deg[Y[i]];
        e[X[i]].push_back(Y[i]);
    }
    for (int i = 1 ; i <= n ; ++ i) {
        if (!deg[i])
            Q.push(i);
    }
    while (!Q.empty()) {
        if (Q.size() > 1)
            return 0;
        int x = Q.front() ; Q.pop();
        for (auto &y : e[x]) {
            if (!-- deg[y])
                Q.push(y);
        }
    }
    return 1;
}

int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < m ; ++ i)
        scanf("%d%d" , X + i , Y + i);
    int l = 0 , r = m;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (!check(r))
        puts("-1");
    else
        cout << r << endl;
    return 0;
}