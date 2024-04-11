#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <cassert>
#include <bitset>
using namespace std;
typedef long long LL;

const int N = 100005;
const int M = 320;
int n , m , Q , a[N];
int B , cnt[M][N];
deque<int> q[M];
void work() {
    int i , j , k , x , y , l , r;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&a[i]) , -- a[i];
    m = sqrt(n) , B = (n + m - 1) / m;

    for (i = 0 ; i < B ; ++ i) {
        int L = i * m;
        for (j = 0 ; j < m && L + j < n ; ++ j) {
            q[i].push_back(a[L + j]);
            ++ cnt[i][a[L + j]];
        }
    }
    scanf("%d",&Q);
    int prev = 0;
    while (Q --) {
        scanf("%d%d%d",&i,&l,&r);
        l = (l + prev - 1) % n;
        r = (r + prev - 1) % n;
        if (l > r) swap(l , r);
        int L = l / m , R = r / m;
        if (i == 2) {
            scanf("%d",&k);
            k = (k + prev - 1) % n;
            int ans = 0;
            if (L == R) {
                int id = L * m;
                for (i = l % m ; i <= r - id ; ++ i) ans += (q[L][i] == k);
            } else {
                for (i = L + 1 ; i < R ; ++ i) ans += cnt[i][k];
                for (i = l % m ; i < m ; ++ i) ans += (q[L][i] == k);
                for (i = r % m ; i >= 0 ; -- i) ans += (q[R][i] == k);
            }
            printf("%d\n" , prev = ans);
        } else {
            if (L == R) {
                x = q[L][r % m];
                q[L].erase(q[L].begin() + r % m);
                q[L].insert(q[L].begin() + l % m , x);
            } else {
                x = q[R][r % m] , -- cnt[R][x];
                q[R].erase(q[R].begin() + r % m);
                q[L].insert(q[L].begin() + l % m , x);
                ++ cnt[L][x];
                for (i = L ; i < R ; ++ i) {
                    x = q[i].back();
                    -- cnt[i][x];
                    q[i].pop_back();
                    q[i + 1].push_front(x);
                    ++ cnt[i + 1][x];
                }
            }
        }
    }

}

int main()
{
    work();
    return 0;
}