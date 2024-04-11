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
const int N = 1000005;

int n , m , dx , dy;
int ans[N];
int Dx[N] , Dy[N] , d[N];
void work() {
    int i , x , y;
    scanf("%d%d%d%d",&n,&m,&dx,&dy);
    for (i = 1 ; i < n ; ++ i) {
        Dx[i] = (Dx[i - 1] + dx) % n;
        Dy[i] = (Dy[i - 1] + dy) % n;
        d[Dx[i]] = Dy[i];
    }
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d",&x , &y);
        y += n - d[x] , y %= n;
        ++ ans[y];
    }
    i = max_element(ans , ans + n) - ans;
    printf("%d %d\n" , 0 , i);
}

int main() {
    work();
    return 0;
}