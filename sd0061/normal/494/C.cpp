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
const int N = 100005;
const int M = 5005;
int n , m;
int a[N];
double sum[N];
pair<int , int> R[M];
double p[M];

pair<int , int> d[M] ; int D;
map< pair<int , int> , int> Node;
bool cmp(pair<int , int> A , pair<int , int> B) {
    if (A.second != B.second)
        return A.second < B.second;
    return A.first > B.first;
}
vector<int> Q[M];
vector<int> E[M];
double f[M][M + M];
int F[17][N];
int LOG[N] , mx;
int val[N];
int RMQ(int l , int r) {
    if (l > r) return 0;
    int j = LOG[r - l + 1];
    return max(F[j][l] , F[j][r - (1 << j) + 1]);
}
double t[M + M];
void dfs(int x) {
    f[x][val[x]] = 1.0;
    for (int i = 0 ; i < E[x].size() ; ++ i) {
        int y = E[x][i];
        dfs(y);
        double q = 0 , w = 0 , tmp = 0;
        for (int j = 0 ; j <= mx ; ++ j) {
            q += f[x][j] , w += f[y][j];
            f[x][j] = (q * w - tmp);
            tmp = q * w;
        }
    }
    for (int i = 0 ; i < Q[x].size() ; ++ i) {
        memset(t , 0 , mx + 1 << 3);
        double P = p[Q[x][i]];
        for (int j = 0 ; j <= mx ; ++ j) {
            t[j] += (1 - P) * f[x][j];
            if (j + 1 <= mx)
                t[j + 1] += P * f[x][j];
        }
        memcpy(f[x] , t , mx + 1 << 3);
    }
}

void work() {
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d", &a[i]);
    }
    int mn = *min_element(a + 1 , a + 1 + n);
    for (i = 1 ; i <= n ; ++ i) {
        a[i] -= mn;
    }
    mx = *max_element(a + 1 , a + 1 + n);
    if (mx >= n) {
        for (i = 1 ; i <= m ; ++ i) {
            scanf("%d%d%lf" , &x , &y , &p[i]);
            sum[x] += p[i];
            sum[y + 1] -= p[i];
        }
        double res = 0;
        for (i = 1 ; i <= n ; ++ i) {
            sum[i] += sum[i - 1];
            res = max(res , a[i] + sum[i] + mn);
        }
        printf("%.10f\n" , res);
        return;
    }
    for (i = 1 ; i <= n ; ++ i)
        F[0][i] = a[i];
    for (i = 0 ; 1 << i <= n ; ++ i)
        LOG[1 << i] = i;
    for (i = 2 ; i <= n ; ++ i)
        if (!LOG[i])
            LOG[i] = LOG[i - 1];
    for (j = 1 ; 1 << j <= n ; ++ j)
        for (i = 1 ; i + (1 << j) - 1 <= n ; ++ i)
            F[j][i] = max(F[j - 1][i] , F[j - 1][i + (1 << j - 1)]);
    d[D ++] = make_pair(1 , n);
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d%lf" , &x , &y , &p[i]);
        R[i] = make_pair(x , y);
        d[D ++] = R[i];
    }
    sort(d , d + D , cmp) , D = unique(d , d + D) - d;
    stack<int> S;
    for (i = 0 ; i < D ; ++ i)
        Node[d[i]] = i;
    for (i = 0 ; i < D ; ++ i) {
        while (!S.empty() && d[i].first <= d[S.top()].first) {
            val[i] = max(val[i] , RMQ(d[S.top()].second + 1 , d[i].second));
            d[i].second = d[S.top()].first - 1;
            E[i].push_back(S.top());
            S.pop();
        }
        val[i] = max(val[i] , RMQ(d[i].first , d[i].second));
        S.push(i);
        //printf("%d : %d\n" , i , val[i]);
    }
    int root = S.top();
    for (i = 0 ; i < m ; ++ i) {
        x = Node[R[i + 1]];
        Q[x].push_back(i + 1);
        //cout << i << ' ' << x << endl;
    }
    mx += m;
    dfs(root);
    double res = mn;
    for (i = 1 ; i <= mx ; ++ i) {
        res += i * f[root][i];
    }
    printf("%.10f\n" , res);
}

int main() {
    work();
    return 0;
}