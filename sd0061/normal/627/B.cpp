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
const int N = 200005;

int n , A , B , K , Q;
int L[N] , R[N];
int cl[N] , cr[N];

int main() {

    scanf("%d%d%d%d%d" , &n , &K , &B , &A , &Q);
    for (int k = 0 ; k < Q ; ++ k) {
        int o , x , y;
        scanf("%d%d" , &o , &x);
        if (o == 1) {
            scanf("%d" , &y);
            int now , delta;
            now = min(A , cl[x] + y);
            delta = now - cl[x];
            cl[x] = now;            
            for (int i = x ; i <= n ; i += i & -i)
                L[i] += delta;            
            now = min(B , cr[x] + y);
            delta = now - cr[x];
            cr[x] = now;
            for (int i = x ; i > 0 ; i -= i & -i)
                R[i] += delta;
        } else {
            int res = 0;
            for (int i = x - 1 ; i > 0 ; i -= i & -i)
                res += L[i];
            for (int i = x + K ; i <= n ; i += i & -i)
                res += R[i];
            printf("%d\n" , res);
        }
    }
    
    return 0;
}