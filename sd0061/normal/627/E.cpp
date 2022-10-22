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
const int N = 3005;

int n , m , P , K;
pair<int , int> a[N];
vector<int> V[N];
int Rank[N][N];
bool vis[N];
int L[N] , R[N];

int main() {

    scanf("%d%d%d%d" , &n , &m , &P , &K);
    for (int i = 0 ; i < P ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        a[i + 1] = make_pair(y , x);
        V[x].push_back(y);
    }
    sort(a + 1 , a + P + 1);
    for (int i = 1 ; i <= P ; ++ i) {
        Rank[a[i].second][a[i].first] = i;
        swap(a[i].first , a[i].second);
    }
    a[0].second = 0 , a[P + 1].second = m + 1;
    LL res = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        memset(vis , 0 , sizeof(vis));
        for (int j = i ; j <= n ; ++ j) {
            for (auto &k : V[j])
                vis[Rank[j][k]] = 1;
        }
        int now = 0;
        L[now] = 0;
        for (int j = 1 ; j <= P + 1 ; ++ j) {
            if (j == P + 1 || vis[j]) {
                R[now] = j;
                L[j] = now;
                now = j;
            }
        }
        R[now] = P + 1;
        res += (LL)m * (m + 1) / 2 * (n - i + 1);
        for (int j = n ; j >= i ; -- j) {
            LL delta = 0;
            for (auto &k : V[j]) {

                int x = Rank[j][k];
                int sum = K , cnt = 0 , y = x;

                while (cnt < K && y) {
                    ++ cnt;
                    y = L[y];
                }
                int z = y;
                for (int T = 0 ; T < K ; ++ T)
                    z = R[z];

                while (z <= P && y < x) {
                    delta += (a[R[y]].second - a[y].second) * (a[R[z]].second - a[z].second);
                    y = R[y];
                    z = R[z];
                }
                L[R[x]] = L[x];
                R[L[x]] = R[x];
            }
            res -= delta * (n - j + 1);
        }
    }
    res = (LL)n * (n + 1) / 2 * m * (m + 1) / 2 - res;
    cout << res << endl;
    return 0;
}