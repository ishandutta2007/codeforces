#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cctype>
#include <set>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , m;
struct edge {
    int x , w , id;
    bool operator < (const edge &R) const {
        if (x != R.x)
            return x < R.x;
        return w < R.w;
    }
}e[N];
int f[N] , s[N];
vector<int> V[N];
set< pair<int , int> > H , S;
pair<int ,int> res[N];
int getf(int x) {
    return f[x] == x ? x : f[x] = getf(f[x]);
}

int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < m ; ++ i) {
        scanf("%d%d" , &e[i].x , &e[i].w);
        e[i].w ^= 1;
        e[i].id = i;
    }
    sort(e , e + m);
    for (int i = 1 ; i <= n ; ++ i) {
        f[i] = i , s[i] = 1;
        V[i].push_back(i);
        S.insert(make_pair(-1 , i));
    }
    for (int i = 0 ; i < m ; ++ i) {
        if (e[i].w) {
            if (H.empty()) {
                puts("-1");
                return 0;
            }
            res[e[i].id] = (*H.begin());
            H.erase(H.begin());            
        } else {
            int x = S.begin() -> second;
            S.erase(S.begin());
            int y = S.begin() -> second;
            S.erase(S.begin());            
            res[e[i].id] = (make_pair(x , y));
            int delta = 100000 - H.size();
            if ((LL) s[x] * s[y] - 1 <= delta)
                delta = s[x] * s[y] - 1;
            for (auto &X : V[x]) {
                for (auto &Y : V[y]) {
                    if (!delta) break;
                    if (x == X && y == Y)
                        continue;
                    -- delta;
                    H.insert(make_pair(X , Y));
                }
                if (!delta) break;
            }
            s[x] += s[y];
            f[y] = x;
            for (auto &Y : V[y])
                V[x].push_back(Y);
            V[y].clear();
            S.insert(make_pair(-s[x] , x));
        }
    }
    for (int i = 0 ; i < m ; ++ i) {
        auto it = res[i];
        printf("%d %d\n" , it.first , it.second);
    }
    return 0;
}