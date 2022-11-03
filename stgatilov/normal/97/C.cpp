#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const double INF = 1e+50;
const int SIZE = 128;
const int K = 210;

struct Edge {
        int a;
        double w;
};

int n;
double prob[SIZE];
vector<Edge> rels[K];
double ans;

double dist[2][K];

int main() {
#ifdef HOME
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif  
        scanf("%d", &n);
        for (int i = 0; i<=n; i++) scanf("%lf", prob+i);

        for (int k = 0; k<K; k++) {
                for (int a = 0; a<=n && a<=k; a++) {
                        Edge e;
                        e.a = k;
                        e.w = prob[a];
                        int b = k - a + n-a;
                        if (b >= K) continue;
                        rels[b].push_back(e);
                }
        }

        ans = 0.0;

        for (int s = 0; s<=n; s++) {
                for (int v = 0; v<K; v++)
                        dist[0][v] = (s==v ? 0.0 : -INF);

                int i;
                for (i = 1; i<K+10; i++) {
                        for (int v = 0; v<K; v++) {
                                double &currd = dist[i&1][v];
                                currd = -INF;
                                for (int t = 0; t<rels[v].size(); t++) {
                                        const Edge &e = rels[v][t];
                                        double tres = dist[(i-1)&1][e.a] + e.w;
                                        if (currd < tres)
                                                currd = tres;
                                }

                                if (v >= s) {
                                        double tans = dist[i&1][v] / i;
                                        if (ans < tans)
                                                ans = tans;
                                }
                        }
                }
        }

        printf("%0.10lf\n", ans);
        return 0;
}