#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 4005;
typedef long long LL;
int n;
LL v[N] , d[N] , p[N];

void Bomb(int x) {
    for (int i = x + 1 ; i < n ; ++ i)
        if (p[i] >= 0) {
            p[i] -= d[x];
            if (p[i] < 0)
                Bomb(i);
        }
}

int main() {
    vector<int> res;
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i)
        scanf("%lld%lld%lld" , &v[i] , &d[i] , &p[i]);
    for (int i = 0 ; i < n ; ++ i) {
        if (p[i] >= 0) {
            vector<int> boom;
            res.push_back(i + 1);
            int x = v[i];
            for (int j = i + 1 ; j < n && x; ++ j)
                if (p[j] >= 0) {
                    p[j] -= x;                   
                    -- x;
                    if (p[j] < 0) {
                        boom.push_back(j);
                    }
                }
            for (auto &it : boom) {
                Bomb(it);
            }
        }         
    }
    printf("%d\n" , (int)res.size());
    for (auto &it : res)
        printf("%d\n" , it);
    return 0;
}