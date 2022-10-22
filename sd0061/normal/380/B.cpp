#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
//typedef long long LL;

const int N = 7005;
int n , m , K;
int p[200000];
int L[N] , R[N] , C[N] , V[N];
int LL[N] , RR[N];
int cnt[1000005] , res;
void work() {
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    for (i = 0 ; 1 << i < 200000 ; ++ i)
        p[1 << i] = 1;
    for (i = 1 ; i < 200000 ; ++ i)
        p[i] += p[i - 1] + 1;
    while (m --) {
        scanf("%d",&j);
        if (j == 1) {
            ++ K;
            scanf("%d%d%d%d",&C[K] , &L[K] , &R[K] , &V[K]);
        } else {
            scanf("%d%d",&x , &y);
            LL[x] = RR[x] = y;
            for (j = x + 1 ; j <= n ; ++ j) {
                LL[j] = p[LL[j - 1] - 1] + 1;
                RR[j] = p[RR[j - 1]];
            }
            for (j = 1 ; j <= K ; ++ j) {
                if (C[j] >= x) {
                    if (min(R[j] , RR[C[j]]) >= max(L[j] , LL[C[j]])) {
                        if (cnt[V[j]] ++ == 0)
                            ++ res;
                    }
                }
            }
            printf("%d\n" , res);
            for (j = 1 ; j <= K ; ++ j) {
                if (C[j] >= x) {
                    if (min(R[j] , RR[C[j]]) >= max(L[j] , LL[C[j]])) {
                        if (! -- cnt[V[j]])
                            -- res;
                    }
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