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
#include <cassert>
#include <cctype>
using namespace std;
typedef long long LL;
const int N = 200005;
pair<int , bool> f[2][N];
int n , m , Q = 1e9 + 7;
void add(pair<int , bool>& A , pair<int , bool> B) {
    A.first += B.first;
    A.second |= B.second;
    if (A.first >= Q)
        A.first -= Q;
}

void work() {
    cin >> n >> m;
    int cur = 0 , nxt = 1;
    int i , j , flag , res = 0;
    f[cur][0] = make_pair(1 , 1);
    for (i = 0 ;  ; ++ i) {
        int x = i * (i + 1) / 2 ;
        pair<int , bool> cnt;
        memset(f[nxt] , 0 , sizeof(f[nxt])) , flag = 0;
        for (j = max(x - m , 0) ; j <= min(x , n) ; ++ j) {
            if (!f[cur][j].second)
                continue;
            add(cnt , f[cur][j]);
            if (j + i + 1 <= n)
                add(f[nxt][j + i + 1] , f[cur][j]);
            if (m - (x - j) >= i + 1)
                add(f[nxt][j] , f[cur][j]);
            flag = 1;
        }
        if (!flag) break;
        res = cnt.first;
        swap(cur , nxt);
    }
    //printf("%d\n" , i - 1);
    printf("%d\n" , res);
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}