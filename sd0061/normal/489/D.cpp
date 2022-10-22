#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 3005;
int n , m;
vector<int> E[N];
int f[N];
queue<int> Q;

void work () {
    int i , j , k , x , y;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d",&x,&y);
        -- x , -- y;
        E[x].push_back(y);
    }
    long long cnt = 0;
    for (i = 0 ; i < n ; ++ i) {
        for (j = 0 ; j < n ; ++ j)
            f[j] = 0;
        for (j = 0 ; j < E[i].size() ; ++ j) {
            x = E[i][j];
            for (k = 0 ; k < E[x].size() ; ++ k) {
                y = E[x][k];
                ++ f[y];
            }
        }
        for (j = 0 ; j < n ; ++ j) if (i != j)
            cnt += f[j] * (f[j] - 1) / 2;
    }
    cout << cnt << endl;
}

int main() {
    work();
    return 0;
}