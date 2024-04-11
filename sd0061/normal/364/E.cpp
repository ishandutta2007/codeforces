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
const int N = 2505;

int n , m , P;
char str[N];
pair<int , int> a[N * N];
vector<int> V[N] , W[N];
int Rank[N][N];
int L[N * N] , R[N * N];
int Begin[N] , End[N];
LL cal(int K) {
    if (K == 0)
        return (LL)-n * (n + 1) / 2 * m * (m + 1) / 2;
    memset(Begin , 0 , sizeof(Begin));
    memset(End , 0 , sizeof(End));
    LL res = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 1 ; j <= n ; ++ j)
            W[j].clear();
        int now = 0;
        L[now] = 0;
        for (int j = 1 ; j <= m ; ++ j) {
            while (Begin[j] < V[j].size() && V[j][Begin[j]] < i) {
                ++ Begin[j];
            }
            while (End[j] < V[j].size() && End[j] - Begin[j] <= K) {
                ++ End[j];
            }
            for (int k = Begin[j] ; k < End[j] ; ++ k) {
                int x = Rank[V[j][k]][j];
                W[V[j][k]].push_back(j);
                R[now] = x;
                L[x] = now;
                now = x;
            }
        }
        R[now] = P + 1;
        L[P + 1] = now;
        R[P + 1] = P + 1;
        for (int j = n ; j >= i ; -- j) {
            LL delta = 0;
            for (auto &k : W[j]) {

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
    return res;
}


int main() {
    int K;
    scanf("%d%d%d" , &n , &m , &K);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%s" , str + 1);
        for (int j = 1 ; j <= m ; ++ j) {
            if (str[j] == '1') {
                V[j].push_back(i);
            }
        }
    }
    P = 0;
    for (int i = 1 ; i <= m ; ++ i) {
        for (auto &x : V[i]) {
            a[++ P] = make_pair(x , i);
            Rank[x][i] = P;
        }
    }
    a[0].second = 0 , a[P + 1].second = m + 1;
    cout << cal(K + 1) - cal(K) << endl;
    return 0;
}